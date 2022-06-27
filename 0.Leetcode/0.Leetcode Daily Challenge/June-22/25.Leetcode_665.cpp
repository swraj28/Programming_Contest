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
	bool checkPossibility(vector<int>& nums) {

		int n = nums.size();

		int cnt = 0;

		for (int i = 1; i < n; i++) {
			if (nums[i] >= nums[i - 1]) {
				continue;
			}

			if (cnt == 1) {
				return false;
			}

			if ((i + 1) >= n) {
				cnt++;
				continue;
			}

			int val = nums[i], val_1 = nums[i - 1], val_2 = nums[i + 1];

			if (val_2 >= val_1) {
				cnt++;
			} else if (val_2 >= val) {

				if ((i - 2) >= 0) {
					if (nums[i - 2] <= nums[i]) {
						cnt++;
					} else {
						return false;
					}
				} else {
					cnt++;
				}
			} else {
				return false;
			}
		}

		return true;
	}
};