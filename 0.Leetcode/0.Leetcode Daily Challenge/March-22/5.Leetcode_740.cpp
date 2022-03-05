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

// Similar to Boredom--> Codeforces.

class Solution {
public:

	int dp[20005];

	unordered_map<int, int> m;

	int maximum_number_points(vector<int> &nums, int n, int si) {
		if (si >= n) {
			return 0;
		}

		if (dp[si] != -1) {
			return dp[si];
		}

		if ((si + 1 < n) && abs(nums[si] - nums[si + 1]) == 1) {
			return dp[si] = max({(m[nums[si]]*nums[si]) + maximum_number_points(nums, n, si + 2), maximum_number_points(nums, n, si + 1)});
		}

		return dp[si] = (m[nums[si]] * nums[si]) + maximum_number_points(nums, n, si + 1);
	}

	int deleteAndEarn(vector<int>& nums) {

		int n = nums.size();

		set<int> s;

		for (int i = 0; i < n; i++) {
			m[nums[i]]++;
			s.insert(nums[i]);
		}

		nums.clear();

		for (auto ele : s) {
			nums.pb(ele);
		}

		sort(all(nums));

		n = nums.size();

		ms(dp, -1);

		return maximum_number_points(nums, n, 0);
	}
};