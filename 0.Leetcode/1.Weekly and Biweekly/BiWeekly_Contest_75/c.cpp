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

	long long numberOfWays(string s) {

		ll n = s.length();

		vector<int> v;

		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (s[i] == s[i - 1]) {
				cnt++;
			} else {
				v.pb(cnt);
				cnt = 1;
			}
		}

		v.pb(cnt);

		if (v.size() < 3) {
			return 0;
		}

		ll ans = 0;

		n = v.size();

		vector<ll> suff_second(n, 0);

		vector<ll> suff(n, 0);

		suff[n - 1] = v[n - 1];
		suff[n - 2] = v[n - 2];

		for (ll i = n - 3; i >= 0; i--) {
			suff[i] = (suff[i + 2] + (ll) v[i]);
		}

		for (ll i = n - 2; i >= 1; i--) {
			suff_second[i] = suff[i + 1];
		}

		vector<ll> suff_sm(n, 0);
		suff_sm[n - 1] = 0;
		suff_sm[n - 2] = (suff_second[n - 2] * (ll)v[n - 2]);

		for (ll i = (n - 3); i >= 0; i--) {
			suff_sm[i] = (suff_sm[i + 2] + (suff_second[i] * (ll)v[i]));
		}

		for (ll i = 0; i <= (n - 3); i++) {
			ans += (v[i] * (ll) suff_sm[i + 1]);
		}

		return ans;
	}
};