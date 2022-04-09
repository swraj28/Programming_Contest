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
	int mostFrequent(vector<int>& nums, int key) {

		int n = nums.size();

		unordered_map<int, int> m;

		for (int i = 0; i < n - 1; i++) {
			if (nums[i] == key) {
				m[nums[i + 1]]++;
			}
		}

		int mx = INT_MIN;
		int val = -1;

		for (auto ele : m) {
			if (ele.ss > mx) {
				mx = ele.ss;
				val = ele.ff;
			}
		}

		return val;
	}
};