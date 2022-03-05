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
	double champagneTower(int poured, int query_row, int query_glass) {

		if (poured == 0) {
			return 0.0000;
		}

		if (query_row == 0) {
			return 1.00000;
		}

		double quantity[101][101] = {0.0};

		quantity[0][0] = poured;

		for (int i = 0; i <= 99; i++) {
			for (int j = 0; j <= i; j++) {
				if (quantity[i][j] > 1.0) {

					double left = (quantity[i][j] - 1.0);

					quantity[i][j] = 1.0;

					quantity[i + 1][j] += (left / (2.0));
					quantity[i + 1][j + 1] += (left / (2.0));
				}
			}
		}

		return min({quantity[query_row][query_glass], 1.0});
	}
};