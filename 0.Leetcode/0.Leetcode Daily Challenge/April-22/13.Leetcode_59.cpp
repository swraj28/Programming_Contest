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

	bool is_ok(int x, int y, int n, int m) {

		if (x < 0 || x >= n || y < 0 || y >= m) {
			return false;
		}

		return true;
	}

	vector<vector<int>> generateMatrix(int n) {

		vector<vector<int>> ans(n, vector<int>(n, 0));

		int val = 1;

		int x = 0, y = 0;

		queue<char> q;

		q.push('r');
		q.push('d');
		q.push('l');
		q.push('u');

		while (val <= (n * n)) {

			auto f = q.front();
			q.pop();
			q.push(f);

			while (val <= (n * n) && is_ok(x, y, n, n) && ans[x][y] == 0) {
				ans[x][y] = val;

				if (f == 'r') {
					y++;
				} else if (f == 'd') {
					x++;
				} else if (f == 'l') {
					y--;
				} else if (f == 'u') {
					x--;
				}

				val++;
			}

			if (is_ok(x, y, n, n) == false || ans[x][y] != 0) {

				if (f == 'r') {
					y--;
					x++;
				} else if (f == 'd') {
					x--;
					y--;
				} else if (f == 'l') {
					y++;
					x--;
				} else if (f == 'u') {
					x++;
					y++;
				}
			}
		}

		return ans;
	}
};