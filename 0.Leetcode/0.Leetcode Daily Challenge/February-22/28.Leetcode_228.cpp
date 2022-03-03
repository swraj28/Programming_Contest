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
	vector<string> summaryRanges(vector<int>& nums) {

		int n = nums.size();

		if (n == 0) {
			return {};
		}

		if (n == 1) {
			return {to_string(nums[0])};
		}

		vector<string> ans;

		string x = to_string(nums[0]);

		bool f = false;

		for (int i = 1; i < n; i++) {

			ll diff = abs((ll)nums[i] - (ll)nums[i - 1]);

			if (diff == 1) {
				if (f == false) {
					f = true;
				}
			} else {
				if (f) {
					x += "->";
					x += to_string(nums[i - 1]);
				}

				ans.pb(x);
				f = false;
				x = to_string(nums[i]);
			}
		}

		if (f) {
			x += "->";
			x += to_string(nums[n - 1]);
		}

		ans.pb(x);

		return ans;
	}
};