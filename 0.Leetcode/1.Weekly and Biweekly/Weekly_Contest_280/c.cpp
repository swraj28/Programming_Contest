#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()
#define ms(arr, v) memset(arr, v, sizeof(arr))

class Solution {
public:
	long long minimumRemoval(vector<int>& beans) {

		int n = beans.size();

		if (n == 1) {
			return 0;
		}

		if (n == 2) {
			return abs(beans[0] - beans[1]);
		}

		bool f = true;

		for (int i = 1; i < n; i++) {
			if (beans[i] != beans[i - 1]) {
				f = false;
				break;
			}
		}

		if (f) {
			return 0;
		}

		sort(all(beans));

		vector<ll> pre(n, 0ll);
		vector<ll> suff(n, 0ll);

		pre[0] = beans[0];

		for (int i = 1; i < n; i++) {
			pre[i] = (pre[i - 1] + (ll) beans[i]);
		}

		suff[n - 1] = beans[n - 1];

		for (int i = n - 2; i >= 0; i--) {
			suff[i] = (suff[i + 1] + (ll) beans[i]);
		}

		ll mn = (1e15);

		int prev = -1;

		for (int i = 0; i < n; i++) {
			if ((i + 1) < n && beans[i] == beans[i + 1]) {
				continue;
			}

			ll total = 0;

			if (prev >= 0) {
				total +=  (ll)pre[prev];
			}

			if ((i + 1) < n) {
				total += (ll)suff[i + 1];

				total -= (beans[i] * (ll)(n - (i + 1)));
			}

			mn = min({mn, total});

			prev = i;
		}

		return mn;
	}
};