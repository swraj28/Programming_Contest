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
	vector<vector<int>> findWinners(vector<vector<int>>& matches) {

		int n = matches.size();
		map<int, int> m;

		for (int i = 0; i < n; i++) {
			m[matches[i][1]]++;
		}

		vector<vector<int>> ans;

		set<int> s;

		for (int i = 0; i < n; i++) {
			if (m.count(matches[i][0]) == 0) {
				s.insert(matches[i][0]);
			}
		}

		vector<int> temp;

		for (auto ele : s) {
			temp.pb(ele);
		}

		ans.pb(temp);
		temp.clear();

		for (auto ele : m) {
			if (ele.ss == 1) {
				temp.pb(ele.ff);
			}
		}

		ans.pb(temp);

		return ans;
	}
};