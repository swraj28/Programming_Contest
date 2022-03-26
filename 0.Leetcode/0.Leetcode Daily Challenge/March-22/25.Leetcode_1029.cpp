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

// The Dynamic Programming Approach is a kind of Brute Force Solution. The Interviewer will surely ask u to optimize the time complexity.

class Solution {
public:

	int dp[205][105][105];

	int recur(vector<vector<int>>& costs, int si, int n, int cnt1 = 0, int cnt2 = 0) {
		if (si >= n) {
			if (cnt1 == (n / 2) && cnt2 == (n / 2)) {
				return 0;
			}

			return (1e8);
		}

		if (dp[si][cnt1][cnt2] != -1) {
			return dp[si][cnt1][cnt2];
		}

		if (cnt1 < n && cnt2 < n) {
			return dp[si][cnt1][cnt2] = min({costs[si][0] + recur(costs, si + 1, n, cnt1 + 1, cnt2), costs[si][1] + recur(costs, si + 1, n, cnt1, cnt2 + 1)});
		}

		if (cnt1 < n) {
			return dp[si][cnt1][cnt2] = costs[si][0] + recur(costs, si + 1, n, cnt1 + 1, cnt2);
		}

		return dp[si][cnt1][cnt2] = costs[si][1] + recur(costs, si + 1, n, cnt1, cnt2 + 1);
	}

	int twoCitySchedCost(vector<vector<int>>& costs) {

		int n = costs.size();

		ms(dp, -1);

		return recur(costs, 0, n);
	}
};


// Optimized:-

/*
    How much money can we save if we fly a person to A vs. B? To minimize the total cost, we should fly the person with the maximum saving to A,
    and with the minimum saving to B.

	Example: [30, 100], [40, 90], [50, 50], [70, 50].
	Savings: 70, 50, 0, -20.

	Obviously, first person should fly to A, and the last - to B.
*/

class Solution {
public:

	int twoCitySchedCost(vector<vector<int>>& costs) {

		int n = costs.size();

		sort(all(costs), [](vector<int> &a, vector<int> &b) {
			return (a[1] - a[0] < b[1] - b[0]);
		});

		int total = 0;

		for (int i = 0; i < n / 2; i++) {
			total += costs[i][1] + costs[i + (n / 2)][0];
		}

		return total;
	}
};
