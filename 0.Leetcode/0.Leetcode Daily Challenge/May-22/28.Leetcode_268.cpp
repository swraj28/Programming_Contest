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
	int missingNumber(vector<int>& nums) {

		int n = nums.size();
		int xor_1 = 0, xor_2 = 0;

		for (int i = 0; i < n; i++) {
			xor_2 ^= nums[i];
		}

		for (int i = 0; i <= n; i++) {
			xor_1 ^= i;
		}

		return xor_1 ^ xor_2;
	}
};