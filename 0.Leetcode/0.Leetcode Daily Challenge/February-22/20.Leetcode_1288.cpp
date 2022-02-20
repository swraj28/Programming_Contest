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
	int removeCoveredIntervals(vector<vector<int>>& intervals) {

		int n = intervals.size();

		sort(all(intervals));

		int l = intervals[0][0], r = intervals[0][1];

		int cnt = 0;

		for (int i = 1; i < n; i++) {

			int l1 = intervals[i][0], r1 = intervals[i][1];

			if (l1 >= l && r1 <= r) {
				cnt++;
			} else if (l >= l1 && r <= r1) {
				cnt++;

				l = l1, r = r1;
			} else {
				l = l1, r = r1;
			}
		}

		return n - cnt;
	}
};