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
	int findJudge(int n, vector<vector<int>>& trust) {

		unordered_map<int, int> m, m1;

		for (int i = 1; i <= n; i++) {
			m[i] = 0;
			m1[i] = 0;
		}

		for (int i = 0; i < trust.size(); i++) {
			int x = trust[i][0], y = trust[i][1];

			m[x]++;

			m1[y]++;
		}

		int x = -1;

		int cnt = 0;

		for (int i = 1; i <= n; i++) {
			if ((m[i] == 0) and (m1[i] == (n - 1))) {
				cnt++;
				x = i;
			}
		}

		if (cnt == 0 or cnt > 1) {
			return -1;
		}

		return x;
	}
};