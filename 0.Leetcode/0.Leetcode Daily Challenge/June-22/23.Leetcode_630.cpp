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

// Approach 1:- Recursion (TLE)--> We cannot memoize this recursive solution as well .

class Solution {
public:

	int recur(vector<vector<int>> &courses, int n, int si, int prev) {
		if (si >= n) {
			return 0;
		}

		if ((prev + courses[si][0]) <= courses[si][1]) {
			return max({1 + recur(courses, n, si + 1, prev + courses[si][0]), recur(courses, n, si + 1, prev)});
		}

		return recur(courses, n, si + 1, prev);
	}

	int scheduleCourse(vector<vector<int>>& courses) {

		int n = courses.size();

		if (n == 1) {
			return 1;
		}

		sort(all(courses), [](vector<int> &a, vector<int> &b) {
			return a[1] < b[1];
		});

		return recur(courses, n, 0, 0);
	}
};

// Appraoch 2: Greedy

class Solution {
public:

	int scheduleCourse(vector<vector<int>>& courses) {

		int n = courses.size();

		if (n == 1) {
			return 1;
		}

		sort(all(courses), [](vector<int> &a, vector<int> &b) {
			return a[1] < b[1];
		});

		priority_queue<int> pq;

		int total_course = 0, total_duration = 0;

		for (int i = 0; i < n; i++) {

			if (courses[i][0] > courses[i][1]) {
				continue;
			}

			int val = ((int)pq.size() > 0) ? pq.top() : 0;

			if ((courses[i][0] + total_duration) <= courses[i][1]) {
				total_duration += courses[i][0];
				pq.push(courses[i][0]);

				total_course++;
			} else if (courses[i][0] < val) {
				pq.pop();
				total_duration -= val;
				total_duration += courses[i][0];

				pq.push(courses[i][0]);
			}
		}

		return total_course;
	}
};