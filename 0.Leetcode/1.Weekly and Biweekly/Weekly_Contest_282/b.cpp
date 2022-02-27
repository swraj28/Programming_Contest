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
	int minSteps(string s, string t) {

		if (s == t) {
			return 0;
		}

		sort(all(s));
		sort(all(t));

		if (s == t) {
			return 0;
		}

		vector<int> cnt_s(26, 0);
		vector<int> cnt_t(26, 0);

		for (auto ch : s) {
			cnt_s[ch - 'a']++;
		}

		for (auto ch : t) {
			cnt_t[ch - 'a']++;
		}

		int ans = 0;

		for (auto ch : s) {
			if (cnt_t[ch - 'a'] > 0) {
				cnt_t[ch - 'a']--;
			} else {
				ans++;
			}
		}

		for (auto ch : t) {
			if (cnt_s[ch - 'a'] > 0) {
				cnt_s[ch - 'a']--;
			} else {
				ans++;
			}
		}

		return ans;
	}
};