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

// T.c:- O(nlog(n)) & S.c:- O(1).

class Solution {
public:
	vector<int> countBits(int n) {

		vector<int> ans;

		for (int i = 0; i <= n; i++) {

			int cnt = 0;
			int x = i;

			// Writing Our own __builtin_popcount() function.
			while (x) {
				cnt++;
				x &= (x - 1);
			}
			ans.push_back(cnt);
		}

		return ans;

	}
};

// Optimization:- Since we are iterating over n states only. Therfore Time Complexity is O(n) & Space Complexity is O(n)

class Solution {
public:

	int recur(int n, vector<int> &dp) {
		if (n == 0) {
			return 0;
		}

		if (n == 1) {
			return 1;
		}

		if (dp[n] != -1) {
			return dp[n];
		}

		if (n % 2 == 0) {
			return dp[n] = recur(n / 2, dp);
		}

		return dp[n] = 1 + recur(n / 2, dp);
	}

	vector<int> countBits(int n) {

		vector<int> ans;

		vector<int> dp(n + 1, -1);

		for (int i = 0; i <= n; i++) {
			ans.pb(recur(i, dp));
		}

		return ans;
	}
};