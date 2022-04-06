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
	bool divideArray(vector<int>& nums) {

		int n = nums.size();
		vector<int>cnt(501, 0);

		for (int i = 0; i < n; i++) {
			cnt[nums[i]]++;
		}

		for (int i = 0; i <= 500; i++) {
			if (cnt[i] % 2) {
				return false;
			}
		}

		return true;
	}
};