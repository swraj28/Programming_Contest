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


// 1. Brute Force Solution:-

class Solution {
public:

	static bool sortcol( const vector<int>& v1, const vector<int>& v2 ) {
		return v1[1] < v2[1];
	}

	bool carPooling(vector<vector<int>>& trips, int capacity) {

		int n = trips.size();

		if (n == 1) {
			return capacity >= trips[0][0];
		}

		sort(all(trips), sortcol);

		// for (int i = 0; i < n; i++) {
		// 	cout << trips[i][0] << " " << trips[i][1] << " " << trips[i][2] << endl;
		// }
		// cout << endl;

		map<int, int> m;
		multiset<int> s;

		bool f = true;

		int toatal = 0;

		for (int i = 0; i < n; i++) {
			int c = trips[i][0];
			int x = trips[i][1], y = trips[i][2];

			for (auto ele : s) {
				if (ele <= x) {
					toatal -= m[ele];
					m[ele] = 0;
				}
			}

			toatal += c;
			s.insert(y);
			m[y] += c;

			if (capacity < toatal) {
				f = false;
				break;
			}
		}

		return f;
	}
};

// 2. Optimized:-

class Solution {
public:

	bool carPooling(vector<vector<int>>& trips, int capacity) {

		int n = trips.size();

		if (n == 1) {
			return capacity >= trips[0][0];
		}

		bool f = true;

		vector<int> v(1005, 0);

		for (int i = 0; i < n; i++) {
			v[trips[i][1]] += trips[i][0];
			v[trips[i][2]] -= trips[i][0];
		}

		int toatal = 0;

		for (auto ele : v) {

			toatal += ele;

			if (toatal > capacity) {
				f = false;
				break;
			}
		}

		return f;
	}
};