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
	int minDeletion(vector<int>& nums) {

		int cnt = 0;
		int n = nums.size();

		for (int i = 0; i < n;) {
			while ((i + 1) < n && nums[i] == nums[i + 1]) {
				cnt++;
				i++;
			}

			i += 2;
		}

		return ((n - cnt) % 2 == 0) ? cnt : cnt + 1;
	}
};