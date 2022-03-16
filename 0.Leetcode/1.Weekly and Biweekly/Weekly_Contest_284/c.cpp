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
	int maximumTop(vector<int>& nums, int k) {

		int n = nums.size();

		if (k == 0) {
			return nums[0];
		}

		if (n == 1 && k % 2) {
			return -1;
		}

		if (n == 1) {
			return nums[0];
		}

		if (k == 1) {
			return nums[1];
		}

		int mx = INT_MIN;

		if (k > n) {
			return (*max_element(all(nums)));
		}

		for (int i = 0; i <= k; i++) {
			if (i == (k - 1)) {
				continue;
			}
			mx = max({mx, nums[i]});
		}

		return mx;
	}
};