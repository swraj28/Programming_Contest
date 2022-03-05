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

/*

index:      0   1   2   3
          +---------------+
nums:   1 | 3 | 1 | 5 | 8 | 1
          +---------------+

	// It may be easier to figure out the recurrence relation by looking at the last step.
	// At the last step, you only have one ballon (3, 1, 5 or 8) to burst, right?
	// So let's have something like opt(END) to denote max coins we can get at the end,
	// we know this opt(END) must come from one of the above 4 cases (by bursting 3, 1, 5 or 8)

	// So it seems like a good idea to use opt(i, j) to represent the max coins we can get from bursting balloons[i, j],
	// let's change opt(END) to opt(i, j) accordingly

	opt(0, 3) = max(
    // If 3 is the last ballon, this means balloons[1, 5, 8] have been burst already,
    // since we don't know the max coins we got by bursting[1, 5, 8], we'll
    // use opt(1, 3) to denote max coins we can get by bursing balloons from 1 to 3, which is [1, 5, 8]
    1 * 3 * 1 + opt(1, 3),
    // Similarily, we have
    1 * 1 * 1 + opt(0, 0) + opt(2, 3),
    1 * 5 * 1 + opt(0, 1) + opt(3, 3),
    1 * 8 * 1 + opt(0, 2)
    )

	// You may have figured out the recurrence relation from the above equation, if not,
	// let's look at how we'll calculate opt(1, 3)
	// Similar to the above equation,

	opt(1, 3) = max(
    	3 * 1 * 1 + opt(2, 3),
    	3 * 5 * 1 + opt(1, 1) + opt(3, 3),
    	3 * 8 * 1 + opt(1, 2)
    )

	// Thus, we have

	>> state:
	opt[i][j] denotes the max coins we can get by bursting balloons[i, j]

	>> recurrence relationship:
	for k from i to j
	max(
    // Edge cases are not considered in the below equation!
    nums[i - 1] * nums[k] * nums[j + 1] + opt[i][k - 1] + opt[k + 1][j]
	)

*/

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