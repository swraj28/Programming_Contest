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
	vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

		int n = grid.size(), m = grid[0].size();

		while (k--) {

			vector<vector<int>> temp = grid;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (j == m - 1) {
						if (i == n - 1) {
							grid[0][0] = temp[i][j];
						} else {
							grid[i + 1][0] = temp[i][j];
						}
					} else {
						grid[i][j + 1] = temp[i][j];
					}
				}
			}
		}

		return grid;
	}
};