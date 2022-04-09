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
	vector<int> topKFrequent(vector<int>& nums, int k) {

		int n = nums.size();
		unordered_map<int, int> m;

		for (int i = 0; i < n; i++) {
			m[nums[i]]++;
		}

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		int sze = 0;

		for (auto ele : m) {

			pq.push({ele.ss, ele.ff});
			sze++;

			if (sze > k) {
				pq.pop();
				sze--;
			}
		}

		vector<int> ans;

		while (!pq.empty()) {
			ans.pb(pq.top().ss);
			pq.pop();
		}

		return ans;
	}
};