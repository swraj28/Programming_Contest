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

// Brute Force:-

class Solution {
public:

	int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	bool is_ok(int x, int y, int n, int m) {

		if (x < 0 || x >= n || y < 0 || y >= m) {
			return false;
		}

		return true;
	}

	void gameOfLife(vector<vector<int>>& board) {

		int n = board.size(), m = board[0].size();

		vector<vector<int>> ans(n, vector<int>(m, 0));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				int cnt = 0;

				for (int k = 0; k < 8; k++) {
					int x = i + dx[k];
					int y = j + dy[k];

					if (is_ok(x, y, n, m)) {
						if (board[x][y] == 1) {
							cnt++;
						}
					}
				}

				if (cnt > 3) {
					ans[i][j] = 0;
				} else if (cnt == 3) {
					if (board[i][j] == 0) {
						ans[i][j] = 1;
					} else {
						ans[i][j] = 1;
					}
				} else if (cnt == 2) {
					if (board[i][j] == 1) {
						ans[i][j] = 1;
					}
				} else {
					ans[i][j] = 0;
				}
			}
		}

		board = ans;
	}
};

// Some Optimization:- (Reducing the space from O(n*m) to O(n)).

class Solution {
public:

	int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	bool is_ok(int x, int y, int n, int m) {

		if (x < 0 || x >= n || y < 0 || y >= m) {
			return false;
		}

		return true;
	}

	void gameOfLife(vector<vector<int>>& board) {

		int n = board.size(), m = board[0].size();

		vector<int> v(n, 0);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				if (board[i][j] == 1) {
					v[i] |= (1 << j);
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				int cnt = 0;

				for (int k = 0; k < 8; k++) {
					int x = i + dx[k];
					int y = j + dy[k];

					if (is_ok(x, y, n, m)) {

						if ((v[x] & (1 << y))) {
							cnt++;
						}
					}
				}

				if (cnt > 3) {
					board[i][j] = 0;
				} else if (cnt == 3) {
					if ((v[i] & (1 << j)) == 0) {
						board[i][j] = 1;
					} else {
						board[i][j] = 1;
					}
				} else if (cnt == 2) {
					if ((v[i] & (1 << j)) == 1) {
						board[i][j] = 1;
					}
				} else {
					board[i][j] = 0;
				}
			}
		}
	}
};

// Optimized Implementation:-

class Solution {
public:

	int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	bool is_ok(int x, int y, int n, int m) {

		if (x < 0 || x >= n || y < 0 || y >= m) {
			return false;
		}

		return true;
	}

	void gameOfLife(vector<vector<int>>& board) {

		int n = board.size(), m = board[0].size();

		// If a cell is '1'
		// ========================
		// neighbors   < 2, it dies
		// neighbors [2,3], it lives
		// neighbors   > 3, it dies

		// If a cell is '0'
		// ========================
		// neighbors   = 3, it becomes '1


		// Hack: To avoid extra space.
		// 0 ===> 0 in both original & new matrix
		// 1 ===> 1 in both original & new matrix
		// 2 ===> 0 in original matrix, 1 in new matrix
		// 3 ===> 1 in original matrix, 0 in new matrix

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				int cnt = 0;

				for (int k = 0; k < 8; k++) {
					int x = i + dx[k];
					int y = j + dy[k];

					if (is_ok(x, y, n, m)) {

						if (board[x][y] == 1 || board[x][y] == 3) {
							cnt++;
						}
					}
				}

				if (board[i][j] == 0 && cnt == 3) {
					board[i][j] = 2;
				} else if (board[i][j] == 1 && (cnt < 2 || cnt > 3)) {
					board[i][j] = 3;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 3) {
					board[i][j] = 0;
				} else if (board[i][j] == 2) {
					board[i][j] = 1;
				}
			}
		}
	}
};