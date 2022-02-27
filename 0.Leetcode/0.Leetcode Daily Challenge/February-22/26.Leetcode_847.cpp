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


// Since we requrie to find the shortest distance we use BFS, but it is not same as the normal bfs.

class Solution {
public:
	int shortestPathLength(vector<vector<int>>& graph) {

		int n = graph.size();

		if (n == 1) {
			return 0;
		}

		int ans = (1 << n) - 1;

		queue < pair<int, pair<int, int>>> q;  //{node,{dist,mask}}
		set<pair<int, int>> visited;  //{node,mask}

		for (int i = 0; i < n; i++) {
			int mask = (1 << i);
			q.push({i, {0, mask}});
			visited.insert({i, mask});
		}

		while (!q.empty()) {

			auto f = q.front();
			q.pop();

			int node = f.ff, dist = f.ss.ff, mask = f.ss.ss;

			if (mask == ans) {
				return dist;
			}

			for (auto nbr : graph[node]) {

				int new_mask = mask | (1 << nbr);

				if (visited.find({nbr, new_mask}) != visited.end()) {
					continue;
				}

				visited.insert({nbr, new_mask});

				q.push({nbr, {dist + 1, new_mask}});
			}
		}

		return 0;
	}
};