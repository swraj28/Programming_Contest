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
	bool isSubsequence(string s, string t) {

		int len = s.length();

		if (len == 0) return true;

		int j = 0;

		for (int i = 0; i < t.length(); i++) {

			if (t[i] == s[j]) {
				len--;
				j++;
			}

			if (len == 0) {
				return true;
			}
		}

		return false;

	}
};

// Approach -2 (LCS)

class Solution {
public:
	bool isSubsequence(string s, string t) {

		int n = s.length();
		int m = t.length();

		// LCS-->(Longest Commom Subsequence)

		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (s[i - 1] == t[j - 1]) {
					dp[i][j] = (1 + dp[i - 1][j - 1]);
				} else {
					dp[i][j] = max({dp[i - 1][j], dp[i][j - 1]});
				}
			}
		}

		return (dp[n][m] == n) ? true : false;
	}
};