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
	int lengthOfLongestSubstring(string s) {

		int n = s.length(), j = 0, mx = 1;

		if (n == 0) {
			return 0;
		}

		vector<int> cnt(128, 0);

		bool f = false;

		for (int i = 0; i < n; i++) {
			cnt[s[i]]++;

			if (cnt[s[i]] == 2) {
				f = true;
			}

			while (f) {
				if (cnt[s[j]] == 2) {
					f = false;
					cnt[s[j++]]--;
				} else {
					cnt[s[j++]]--;
				}
			}

			mx = max(mx, ((i - j) + 1));

			// cout<<(i-j)+1<<" "<<j<<" "<<i<<endl;
		}

		return mx;
	}
};