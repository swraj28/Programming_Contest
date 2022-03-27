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
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

		int n = mat.size(), m = mat[0].size();
		set<pair<int, int>> s;

		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 1) {
					cnt++;
				}
			}

			s.insert({cnt, i});
		}

		vector<int> ans;

		for (int i = 0; i < k; i++) {
			ans.pb((*s.begin()).ss);
			s.erase(s.begin());
		}

		return ans;
	}
};