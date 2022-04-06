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
	long long maximumSubsequenceCount(string text, string pattern) {

		int n = text.length();

		ll ans = 0;

		bool f = true;

		ll cnt_0 = 0, cnt_1 = 0;

		for (int i = 0; i < n; i++) {
			if (text[i] == pattern[0]) {
				cnt_0++;
			} else if (text[i] == pattern[1]) {
				cnt_1++;

				ans += (ll)(cnt_0);
			}
		}

		if (pattern[0] == pattern[1]) {
			cnt_0++;

			ans = (cnt_0 * (ll)(cnt_0 - 1)) / 2;
			return ans;
		}

		if (f) {
			ans += (ll)max(cnt_0, cnt_1);
		}

		return ans;
	}
};