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
	int maximumUniqueSubarray(vector<int>& nums) {

		int n = nums.size();

		vector<int> pre_sm(n, 0);

		pre_sm[0] = nums[0];

		for (int i = 1; i < n; i++) {
			pre_sm[i] = (pre_sm[i - 1] + nums[i]);
		}

		int j = 0, mx = 0;

		unordered_set<int> s;

		for (int i = 0; i < n; i++) {

			if (s.count(nums[i]) == 0) {
				s.insert(nums[i]);
			} else {

				while (nums[j] != nums[i]) {
					s.erase(s.find(nums[j]));
					j++;
				}

				s.erase(s.find(nums[j]));
				j++;

				s.insert(nums[i]);
			}

			int total = pre_sm[i];

			if ((j - 1) >= 0) {
				total -= pre_sm[j - 1];
			}

			mx = max(mx, total);
		}

		return mx;
	}
};