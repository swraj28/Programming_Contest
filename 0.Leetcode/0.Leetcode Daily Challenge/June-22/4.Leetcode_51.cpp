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

	vector<vector<string>> ans;

	bool is_valid(vector<string> &v, int n, int row, int col) {

		for (int i = 0; i < row; i++) {
			if (v[i][col] == 'Q') {
				return false;
			}
		}

		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
			if (v[i][j] == 'Q') {
				return false;
			}
		}

		for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
			if (v[i][j] == 'Q') {
				return false;
			}
		}

		return true;
	}

	void recur(vector<string> &v, int n, int row) {
		if (row >= n) {
			ans.pb(v);

			return;
		}

		for (int col = 0; col < n; col++) {
			if (is_valid(v, n, row, col)) {
				v[row][col] = 'Q';
				recur(v, n, row + 1);
				v[row][col] = '.';
			}
		}
	}

	vector<vector<string>> solveNQueens(int n) {

		vector<string>v(n, std::string(n, '.'));

		recur(v, n, 0);

		return ans;
	}
};