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

	int recur(string &a, string &b, int n, int m, int si1, int si2, vector<vector<int>> &dp) { // This function will return the length of lcs

		if (si1 >= n or si2 >= m) {
			return 0;
		}

		if (dp[si1][si2] != -1) {
			return dp[si1][si2];
		}

		if (a[si1] == b[si2]) {
			return dp[si1][si2] = 1 + recur(a, b, n, m, si1 + 1, si2 + 1, dp);
		}

		return dp[si1][si2] = max({recur(a, b, n, m, si1 + 1, si2, dp), recur(a, b, n, m, si1, si2 + 1, dp)});
	}

	int longestCommonSubsequence(string text1, string text2) {

		int n = text1.length();
		int m = text2.length();

		vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

		int ans = recur(text1, text2, n, m, 0, 0, dp);

		return ans;
	}

	int minDistance(string word1, string word2) {

		int n = word1.length(), m = word2.length();

		int ans = longestCommonSubsequence(word1, word2);

		return (n + m) - (2 * ans);
	}
};