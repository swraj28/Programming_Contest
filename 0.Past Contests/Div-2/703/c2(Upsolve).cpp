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
	vector<int> findSubarray(int a[], int n) {

		bool f = false;

		for (int i = 0; i < n; i++) {
			if (a[i] >= 0) {
				f = true;
				break;
			}
		}

		if (f == false) {
			return { -1};
		}

		ll mx = 0, idx = -1, len = 0;

		ll st = 0, sm = 0;

		for (ll i = 0; i < n;) {

			if (a[i] < 0) {
				ll t_len = (i - st);

				if (sm > mx) {
					mx = sm;
					idx = st;
					len = t_len;
				} else if (sm == mx) {
					if (t_len > len) {
						mx = sm;
						len = t_len;
						idx = st;
					} else if (st < idx) {
						mx = sm;
						len = t_len;
						idx = st;
					}
				}

				while ((i < n) && a[i] < 0) {
					i++;
				}

				st = i;
				sm = 0;
			} else {
				sm += (ll) a[i];
				i++;
			}
		}

		if (st < n) {

			ll t_len = (n - st);

			if (sm > mx) {
				mx = sm;
				idx = st;

				len = t_len;
			} else if (sm == mx) {
				if (t_len > len) {
					mx = sm;
					len = t_len;
					idx = st;
				} else if (st < idx) {
					mx = sm;
					len = t_len;
					idx = st;
				}
			}
		}

		vector<int> ans;

		while (len--) {
			ans.push_back(a[idx]);
			idx++;
		}

		return ans;
	}
};