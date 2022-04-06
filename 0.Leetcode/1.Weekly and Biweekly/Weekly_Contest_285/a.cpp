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
	int countHillValley(vector<int>& nums) {

		int n = nums.size();
		int cnt = 0;

		int idx = 1;

		while (idx < n) {

			while (idx < n && nums[idx] == nums[idx - 1]) {
				idx++;
			}

			bool f = false;

			while (idx < n && nums[idx] >= nums[idx - 1]) {
				if (!f) {
					f = true;
				}
				idx++;
			}

			if (idx < n && f == true) {
				cnt++;
			}

			while (idx < n && nums[idx] == nums[idx - 1]) {
				idx++;
			}

			f = false;

			while (idx < n && nums[idx] <= nums[idx - 1]) {
				if (!f) {
					f = true;
				}
				idx++;
			}

			if (idx < n && f == true) {
				cnt++;
			}

		}

		return cnt;
	}
};