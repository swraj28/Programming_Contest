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
	int numberOfArithmeticSlices(vector<int>& nums) {

		int n = nums.size();

		if (n < 3) {
			return 0;
		}

		int cnt = 2;
		int d = (nums[0] - nums[1]);

		int ans = 0;

		for (int i = 1; i < n;) {
			if ((i + 1) < n) {
				int d1 = (nums[i] - nums[i + 1]);
				if (d1 == d) {
					cnt++;
					i++;
				} else {
					int val = (cnt - 3) + 1;

					if (val >= 0) {
						ans += (val * (val + 1)) / 2;
					}

					cnt = 2;
					d = (nums[i] - nums[i + 1]);
					i += 1;
				}
			} else {
				break;
			}
		}

		int val = (cnt - 3) + 1;

		if (val >= 0) {
			ans += (val * (val + 1)) / 2;
		}

		return ans;
	}
};