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

	int dp[305][305];

	int recur(vector<int> &nums, int n, int l, int r) { // This Function will return max points gained by bursting the ballons
		if (l > r) {
			return 0;
		}

		if (dp[l][r] != -1) {
			return dp[l][r];
		}

		int mx = INT_MIN;

		for (int i = l; i <= r; i++) {

			//the Cost val here is Cost if the Last Element in the arr is Bursted : a[left-1]*a[last]*a[right+1]

			int val = nums[i];

			if ((l - 1) >= 0) {
				val *= nums[l - 1];
			}

			if ((r + 1) < n) {
				val *= nums[r + 1];
			}

			int rec_res_1 = recur(nums, n, l, i - 1);
			int rec_res_2 = recur(nums, n, i + 1, r);

			int profit = (val + rec_res_1 + rec_res_2);

			mx = max({mx, profit});
		}

		return dp[l][r] = mx;
	}

	int maxCoins(vector<int>& nums) {

		int n = nums.size();

		ms(dp, -1);

		return recur(nums, n, 0, n - 1);
	}
};