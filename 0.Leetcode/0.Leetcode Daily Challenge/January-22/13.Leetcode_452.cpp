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

	// Non Overlapping Intervals:-

	/*

	    Key Points for Overlapping Interval Problems:-

	    1.Sort intervals/pairs in increasing order of the start position.

		2.Scan the sorted intervals, and maintain an "active set" for overlapping intervals.
		  At most times, we do not need to use an explicit set to store them.
		  Instead, we just need to maintain several key parameters, e.g. the number of overlapping intervals (count),
		  the minimum ending point among all overlapping intervals (minEnd).

		3.If the interval that we are currently checking overlaps with the active set, which can be characterized by cur.start > minEnd,
			we need to renew those key parameters or change some states.

		4.If the current interval does not overlap with the active set,
			we just drop current active set, record some parameters, and create a new active set that contains the current interval.

	*/


	static bool sortcol( const vector<int>& v1, const vector<int>& v2 ) {
		if (v1[0] == v2[0]) {
			return v1[1] < v2[1];
		}

		return v1[0] < v2[0];
	}

	int findMinArrowShots(vector<vector<int>>& points) {

		int n = points.size();

		sort(all(points), sortcol);

		// for (int i = 0; i < n; i++) {
		// 	cout << points[i][0] << " " << points[i][1] << endl;
		// }

		int cnt = 1;

		int l = points[0][0], r = points[0][1];

		for (int i = 1; i < n; i++) {
			int l1 = points[i][0], r1 = points[i][1];

			if (l1 <= r) {
				l = l1;
				r = min(r, r1);
			} else {
				cnt++;
				l = l1, r = r1;
			}
		}

		return cnt;

		return 0;
	}
};