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

/*

     Appraoch:-   Run Three Dijkastra.

     Youtube Link:- https://www.youtube.com/watch?v=tcXJTUwb-jc&t=577s&ab_channel=CodingDecoded

*/

const ll INF (1e15);

class Solution {
public:

	void dijkstra(vector<pair<ll, ll>> adj[] , ll n, ll s, vector<ll> & d) {

		d.assign(n, INF);

		d[s] = 0ll;

		set<pair<ll, ll>> q;

		q.insert({0, s});  // {distance,node}

		while (!q.empty()) {

			ll v = q.begin()->second;

			q.erase(q.begin());

			for (auto edge : adj[v]) {

				ll to = edge.first;

				ll len = edge.second;

				if (d[v] + len < d[to]) {

					auto itr = q.find({d[to], to});

					if (itr != q.end()) {
						q.erase({d[to], to});
					}

					d[to] = d[v] + len;

					q.insert({d[to], to});
				}
			}
		}
	}

	long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {

		vector<pair<ll, ll>> gr[n];
		vector<pair<ll, ll>> rev_gr[n];

		for (auto edge : edges) {
			ll x = edge[0], y = edge[1], w = edge[2];

			gr[x].pb({y, w});
			rev_gr[y].pb({x, w});
		}

		vector<ll> d1, d2;

		dijkstra(gr, n, (ll)src1, d1);
		dijkstra(gr, n, (ll)src2, d2);

		vector<ll> d3;

		dijkstra(rev_gr, n, (ll)dest, d3);

		ll mn = (1e13);

		for (ll i = 0; i < n; i++) {
			ll d = d1[i] + (ll) d2[i] + (ll) d3[i];

			mn = min({mn, d});
		}

		return (mn == 1e12) ? -1 : mn;
	}
};