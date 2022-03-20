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
	string removeDuplicateLetters(string s) {

		int n = s.length();
		vector<int> cnt(26, 0);
		vector<int> visited(26, 0);

		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'a']++;
		}

		string ans = "";

		int sze = 0;

		for (int i = 0; i < n; i++) {

			if (visited[s[i] - 'a']) {
				cnt[s[i] - 'a']--;
				continue;
			}

			if (sze == 0) {
				ans += s[i];
				sze++;
				visited[s[i] - 'a'] = 1;
				cnt[s[i] - 'a']--;

				continue;
			}

			while (sze > 0 && s[i] < ans[sze - 1] && cnt[ans[sze - 1] - 'a'] > 0) {
				char x = ans[sze - 1];
				ans.pop_back();
				visited[x - 'a'] = 0;
				sze -= 1;
			}

			ans += s[i];
			visited[s[i] - 'a'] = 1;
			cnt[s[i] - 'a']--;
			sze++;
		}

		return ans;
	}
};