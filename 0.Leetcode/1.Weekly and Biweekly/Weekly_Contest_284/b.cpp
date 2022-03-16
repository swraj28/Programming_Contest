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
	int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {

		set<pair<int, int>> s;

		for (auto v : dig) {
			s.insert({v[0], v[1]});
		}

		int cnt = 0;

		for (int i = 0; i < artifacts.size(); i++) {
			int a = artifacts[i][0], b = artifacts[i][1], c = artifacts[i][2], d = artifacts[i][3];

			bool f = true;

			for (int j = a; j <= c; j++) {
				for (int k = b; k <= d; k++) {
					if (s.find({j, k}) == s.end()) {
						f = false;
						break;
					}

					s.erase({j, k});
				}

				if (f == false) {
					break;
				}
			}

			if (f) {
				cnt++;
			}
		}

		return cnt;
	}
};