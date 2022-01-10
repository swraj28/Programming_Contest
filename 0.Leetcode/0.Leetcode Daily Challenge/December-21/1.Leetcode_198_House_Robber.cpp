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

	int dp[105];

	int recur(vector<int> &nums, int si, int n) { // This function will return us the maximum theivery
		if (si >= n) {
			return 0;
		}

		if (dp[si] != -1) {
			return dp[si];
		}

		int a = nums[si] + recur(nums, si + 2, n);
		int b = recur(nums, si + 1, n);

		return dp[si] = max({a, b});
	}

	int rob(vector<int>& nums) {

		int n = nums.size();

		memset(dp, -1, sizeof(dp));

		return recur(nums, 0, n);
	}
};