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
	int findDuplicate(vector<int>& nums) {

		int n = nums.size();
		int x = -1;
		unordered_set<int> s;

		for (int i = 0; i < n; i++) {
			if (s.find(nums[i]) != s.end()) {
				x = nums[i];
				break;
			} else {
				s.insert(nums[i]);
			}
		}

		return x;
	}
};