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
	int numPairsDivisibleBy60(vector<int>& time) {

		int n = time.size();

		unordered_map<int, int> m;

		int cnt = 0;

		for (int i = 0; i < n; i++) {

			int x = (time[i] % 60);

			int req = (60 - x) % 60;

			if (m.find(req) != m.end()) {
				cnt += m[req];
			}

			m[x]++;
		}

		return cnt;
	}
};