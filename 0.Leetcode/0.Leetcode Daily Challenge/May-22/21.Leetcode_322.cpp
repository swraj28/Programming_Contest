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

	long long memo[100000];

	long long dp(vector<int>& coins, int m) {
		if (m == 0) return 0;

		if (memo[m] != -1) return memo[m];

		long long best = INT_MAX;

		for (int x = 0; x < coins.size(); x++) {
			if (m >= coins[x]) {
				best = min(best, dp(coins, m - coins[x]) + 1);
			}
		}

		return memo[m] = best;
	}

public:
	int coinChange(vector<int>& coins, int amount) {

		int n = coins.size();
		if (amount == 0) return 0;

		if (n == 0) return -1;

		memset(memo, -1, sizeof(memo));

		long long c = dp(coins, amount);

		return c == INT_MAX ? -1 : c;
	}
};