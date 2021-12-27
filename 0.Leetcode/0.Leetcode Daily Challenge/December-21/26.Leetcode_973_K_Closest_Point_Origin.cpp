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
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

		vector<vector<int>> ans;

		int n = points.size();

		priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>> , greater<pair<int, pair<int, int>>> > pq;

		for (int i = 0; i < n; i++) {
			int x = points[i][0], y = points[i][1];

			int d = pow(x, 2) + pow(y, 2);

			d = sqrt(d);

			pq.push({d, {x, y}});
		}

		vector<int> v;

		while (k > 0) {
			auto p = pq.top();
			pq.pop();

			v.clear();

			v.pb(p.ss.ff);
			v.pb(p.ss.ss);

			k -= 1;

			ans.pb(v);
		}

		return ans;
	}
};