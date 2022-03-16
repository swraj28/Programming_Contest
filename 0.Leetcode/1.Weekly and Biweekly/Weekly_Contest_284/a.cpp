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
	vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {

		set<int> s;
		int n = nums.size();

		for (int i = 0; i < n; i++) {
			if (nums[i] == key) {
				s.insert(i);

				int j = i - 1;

				while (j >= 0 && abs(j - i) <= k) {
					s.insert(j);
					j -= 1;
				}

				j = i + 1;

				while (j < n && abs(j - i) <= k) {
					s.insert(j);
					j += 1;
				}
			}
		}

		vector<int> ans;

		for (auto ele : s) {
			ans.pb(ele);
		}

		return ans;
	}
};