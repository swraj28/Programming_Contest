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

	ll dp[1005][2005];

	ll recur(vector<vector<int>> &piles, int n, int si, int k) {
		if (k == 0) {
			return 0;
		}

		if (si >= n) {
			return (-1e12);
		}

		if (dp[si][k] != -1) {
			return dp[si][k];
		}

		ll mx = 0;

		ll sm = 0;
		for (ll val = 0; val < min((int)piles[si].size(), k); val++) {
			sm += piles[si][val];

			mx = max({mx, sm + recur(piles, n, si + 1, k - (val + 1)), recur(piles, n, si + 1, k)});
		}

		return dp[si][k] = mx;
	}

	int maxValueOfCoins(vector<vector<int>>& piles, int k) {

		int n = piles.size();

		ms(dp, -1ll);

		ll ans = recur(piles, n, 0, k);

		return ans;
	}
};