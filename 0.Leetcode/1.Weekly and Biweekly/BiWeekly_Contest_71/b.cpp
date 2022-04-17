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
	vector<int> pivotArray(vector<int>& nums, int pivot) {

		int n = nums.size();
		int c1 = 0, c2 = 0;

		for (int i = 0; i < n; i++) {
			if (nums[i] < pivot) {
				c1++;
			} else if (nums[i] > pivot) {
				c2++;
			}
		}

		int idx1 = 0, idx2 = c1, idx3 = (n - c2);

		vector<int> ans(n, 0);

		for (int i = 0; i < n; i++) {
			if (nums[i] < pivot) {
				ans[idx1] = nums[i];
				idx1++;
			} else if (nums[i] == pivot) {
				ans[idx2] = nums[i];
				idx2++;
			} else {
				ans[idx3] = nums[i];
				idx3++;
			}
		}

		return ans;
	}
};