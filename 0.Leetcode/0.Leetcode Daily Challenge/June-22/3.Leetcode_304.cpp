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

class NumMatrix {
public:

	vector<vector<int>> aux;

	NumMatrix(vector<vector<int>>& matrix) {

		int n = matrix.size(), m = matrix[0].size();

		aux = vector<vector<int>>(n, vector<int>(m, 0));

		aux[0][0] = matrix[0][0];

		for (int i = 1; i < n; i++) {
			aux[i][0] = (aux[i - 1][0] + matrix[i][0]);
		}

		for (int i = 1; i < m; i++) {
			aux[0][i] = (aux[0][i - 1] + matrix[0][i]);
		}

		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				aux[i][j] = (aux[i][j - 1] + aux[i - 1][j] + matrix[i][j]) - aux[i - 1][j - 1];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {

		int val = aux[row2][col2];

		if ((row1 - 1) >= 0 && (col1 - 1) >= 0) {
			val += aux[row1 - 1][col1 - 1];

			val -= aux[row2][col1 - 1];
			val -= aux[row1 - 1][col2];
		} else if ((row1 - 1) >= 0) {
			val -= aux[row1 - 1][col2];
		} else if ((col1 - 1) >= 0) {
			val -= aux[row2][col1 - 1];
		}

		return val;
	}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */