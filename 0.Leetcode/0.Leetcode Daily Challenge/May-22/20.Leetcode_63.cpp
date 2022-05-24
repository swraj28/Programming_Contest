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

	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

		int n = obstacleGrid.size(), m = obstacleGrid[0].size();

		vector<vector<int>> dp(n, vector<int>(m, 0));

		for (int i = 0; i < n; i++) {
			if (obstacleGrid[i][0] == 1) {
				break;
			}
			dp[i][0] = 1;
		}

		for (int j = 0; j < m; j++) {
			if (obstacleGrid[0][j] == 1) {
				break;
			}
			dp[0][j] = 1;
		}


		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				if (obstacleGrid[i][j] == 1) {
					continue;
				}

				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]);
			}
		}

		return dp[n - 1][m - 1];
	}
};