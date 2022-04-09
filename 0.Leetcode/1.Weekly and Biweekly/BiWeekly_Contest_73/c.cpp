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

	vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

		vector<int> gr[n];

		for (auto edge : edges) {
			gr[edge[0]].pb(edge[1]);
		}

		vector<int> indegree(n, 0);

		for (int i = 0; i < n; i++) {
			for (auto nbr : gr[i]) {
				indegree[nbr]++;
			}
		}

		queue<int> q;

		for (int i = 0; i < n; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		set<int> res[n];

		while (!q.empty()) {
			auto f = q.front();
			q.pop();

			for (auto nbr : gr[f]) {
				res[nbr].insert(f);

				for (auto x : res[f]) {
					res[nbr].insert(x);
				}
			}

			for (auto nbr : gr[f]) {
				indegree[nbr] -= 1;

				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}

		vector<vector<int>> ans;

		vector<int> temp;

		for (int i = 0; i < n; i++) {
			temp.clear();
			for (auto ele : res[i]) {
				temp.pb(ele);
			}

			ans.pb(temp);
		}

		return ans;
	}
};