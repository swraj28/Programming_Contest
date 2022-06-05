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
	vector<int> runningSum(vector<int>& nums) {

		int n = nums.size();

		vector<int> pre_sm(n, 0);
		pre_sm[0] = nums[0];

		for (int i = 1; i < n; i++) {
			pre_sm[i] = (pre_sm[i - 1] + nums[i]);
		}

		return pre_sm;
	}
};