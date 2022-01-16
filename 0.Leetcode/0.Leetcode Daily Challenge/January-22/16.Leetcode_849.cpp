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
	int maxDistToClosest(vector<int>& seats) {

		int n = seats.size();

		int st = 0;

		int mx = 0;

		bool f = true;

		for (int i = 0; i < n; i++) {
			if (seats[i] == 1) {
				if (f) {
					int d = (i - st);
					f = false;
					mx = max(mx, d);
					st = i;
					continue;
				}

				int d = (i - st) / 2;
				mx = max(mx, d);
				st = i;
			}
		}

		int d = ((n - 1) - st);
		mx = max(mx, d);

		return mx;
	}
};