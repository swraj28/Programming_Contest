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
	int findMaxLength(vector<int>& nums) {

		int n = nums.size();

		int mx = 0;

		unordered_map<int, int> m;

		int x = 0;

		for (int i = 0; i < n; i++) {
			if (nums[i]) {
				x++;
			} else {
				x--;
			}

			if (x == 0) {
				mx = max({mx, (i + 1)});
			} else {
				if (m.find(x) != m.end()) {
					int d = (i - m[x]);
					mx = max(d, mx);
				} else {
					m[x] = i;
				}
			}
		}

		return mx;
	}
};