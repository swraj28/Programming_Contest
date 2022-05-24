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

// Using Extra Space:-

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {

		int n = nums.size();

		vector<int> ans(n);

		int st = 0, end = n - 1;

		for (int i = 0; i < n; i++) {
			if (nums[i] % 2 == 0) {
				ans[st] = nums[i];
				st++;
			} else {
				ans[end] = nums[end];
				end--;
			}
		}

		return ans;
	}
};

// Without Extra Space:-

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {

		int n = nums.size();

		int st = 0;

		for (int i = 0; i < n; i++) {
			if (nums[i] % 2 == 0) {
				swap(nums[i], nums[st]);
				st++;
			}
		}

		return nums;
	}
};