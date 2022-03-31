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
	int splitArray(vector<int>& nums, int m) {

		int n = nums.size();

		int sm = 0;

		for (auto ele : nums) {
			sm += ele;
		}

		if (sm == 0) {
			return 0;
		}

		int st = 0, end = (1e9);

		while (st + 1 < end) {

			int mid = (st + (end - st) / 2);

			int val = 0;
			int temp_sm = 0;

			bool f = true;

			for (int i = 0; i < n; i++) {

				if (nums[i] > mid) {
					f = false;
					break;
				}

				if ((temp_sm + nums[i]) <= mid) {
					temp_sm += nums[i];
				} else {
					temp_sm = nums[i];
					val++;
				}
			}

			if (f == false) {
				st = mid;
				continue;
			}

			if (temp_sm) {
				val++;
			}

			if (val <= m) {
				end = mid;
			} else {
				st = mid;
			}
		}

		return end;
	}
};