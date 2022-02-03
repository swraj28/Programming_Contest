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
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

		int n = nums1.size();

		unordered_map<int, int> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x = nums3[i] + nums4[j];

				m[x]++;
			}
		}

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x = nums1[i] + nums2[j];

				if (m.find(-x) != m.end()) {
					cnt += m[-x];
				}
			}
		}

		return cnt;
	}
};