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
	int dp[1001][1001];
	int suffix[1001];

	void findSuffixSum(string& floor) {
		int n = floor.size();

		suffix[n - 1] = (floor[n - 1] == '1');
		for (int i = n - 2; i >= 0; i--) {
			suffix[i] = suffix[i + 1] + (floor[i] == '1');
		}
	}

	int solve(string& floor, int numCarpets, int carpetLen, int pos, int used) { // This function will tell min number of whiltes left.
		if (pos >= floor.size()) {
			return 0;
		} else if (used == numCarpets) {
			return suffix[pos];
		}

		if (dp[pos][used] != -1) {
			return dp[pos][used];
		}

		return dp[pos][used] = min(solve(floor, numCarpets, carpetLen, pos + carpetLen, used + 1), (floor[pos] == '1') + solve(floor, numCarpets, carpetLen, pos + 1, used));
	}

	int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
		memset(dp, -1, sizeof(dp));
		findSuffixSum(floor);

		return solve(floor, numCarpets, carpetLen, 0, 0);
	}
};