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

// Brute Force:-

class Solution {
public:
	void rotate(vector<int>& nums, int k) {

		int n = nums.size();

		k %= n;
		if (k == 0) {
			return;
		}

		int idx1 = 0, idx2 = (n - k);

		vector<int> v;

		for (int i = idx2; i < n; i++) {
			v.pb(nums[i]);
		}

		for (int i = idx1; i < idx2; i++) {
			v.pb(nums[i]);
		}

		nums = v;
	}
};

class Solution {
public:
	void rotate(vector<int>& nums, int k) {

		int n = nums.size();

		k %= n;
		if (k == 0) {
			return;
		}

		int idx1 = 0, idx2 = (n - k);


	}
};