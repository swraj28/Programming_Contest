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

	int find_parent(int v, vector<int> &parent) {
		if (v == parent[v]) {
			return v;
		}

		return parent[v] = find_parent(parent[v], parent);
	}

	string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {

		int n = s.length();

		vector<int> parent(n);
		vector<int> sze(n);

		for (int i = 0; i < n; i++) {
			parent[i] = i;
			sze[i] = 1;
		}

		for (auto p : pairs) {
			int a = p[0], b = p[1];

			a = find_parent(a, parent);
			b = find_parent(b, parent);

			if (a == b) {
				continue;
			}

			if (sze[a] >= sze[b]) {
				parent[b] = a;
				sze[a] += sze[b];
			} else {
				parent[a] = b;
				sze[b] += sze[a];
			}
		}

		map<int, multiset<char>> m;

		for (int i = 0; i < n; i++) {
			int x = find_parent(i, parent);

			m[x].insert(s[i]);
		}

		for (int i = 0; i < n; i++) {
			int x = find_parent(i, parent);

			s[i] = *(m[x].begin());
			m[x].erase(m[x].begin());
		}

		return s;
	}
};