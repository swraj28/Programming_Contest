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
	int findPairs(vector<int>& nums, int k) {

		int n = nums.size();

		set<pair<int, int>> st;

		unordered_set<int> s;

		for (int i = 0; i < n; i++) {

			int x = nums[i];

			if (s.find(x - k) != s.end()) {
				st.insert({(x - k), x});
			}

			if (s.find(x + k) != s.end()) {
				st.insert({x, (x + k)});
			}
		}

		return st.size();
	}
};

//******************************************************************

class Solution {
public:
	int findPairs(vector<int>& nums, int k) {

		int n = nums.size();

		unordered_map<int, int> m;

		for (int i = 0; i < n; i++) {
			m[nums[i]]++;
		}

		int cnt = 0;

		for (int i = 0; i < n; i++) {

			int x = nums[i];

			if (m[x] == 0) {
				continue;
			}

			if ((k == 0 && m[x] > 1) || ((k && m[x - k] > 0))) {
				cnt++;
			}

			if ((k && m[x + k] > 0)) {
				cnt++;
			}

			m[x] = 0;
		}

		return cnt;
	}
};