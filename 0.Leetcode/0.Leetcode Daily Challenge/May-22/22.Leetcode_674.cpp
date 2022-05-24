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

	int count_Palindrome(string s) {

		int n = s.length();

		vector<vector<int>> dp(n, vector<int>(n, 0));

		int cnt = 0;

		for (int i = 0; i < n; i++) {  // 1 length pailendeome
			cnt++;
			dp[i][i] = 1;
		}

		// 2 length pailendrome

		int st = -1, end = -1;

		for (int i = 0; i < n - 1; i++) {
			if (s[i] == s[i + 1]) {
				dp[i][i + 1] = 1;
				cnt++;
			}
		}

		// for 3 and more length pailengrome

		for (int len = 3; len <= n; len++) {

			for (int i = 0; i <= (n - len); i++) {
				if ((s[i] == s[i + (len - 1)]) and (dp[i + 1][i + (len - 2)] == 1)) {
					dp[i][i + (len - 1)] = 1;
					cnt++;
				}
			}
		}

		return cnt;
	}

	int countSubstrings(string s) {

		return count_Palindrome(s);
	}
};