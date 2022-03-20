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
	int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {

		int n = tops.size();

		int a = tops[0], b = bottoms[0];

		for (int i = 1; i < n; i++) {

			if (a == -1 && b == -1) {
				return -1;
			}

			if (tops[i] == a || bottoms[i] == a) {

				if (tops[i] == b || bottoms[i] == b) {

				} else {
					b = -1;
				}
			} else {
				a = -1;

				if (tops[i] == b || bottoms[i] == b) {

				} else {
					b = -1;
				}
			}
		}

		int val1, val2;

		if (a != -1) {
			val1 = 0;

			int cnt = 0;

			for (int i = 0; i < n; i++) {
				if (tops[i] == a) {
					continue;
				}

				cnt++;
			}

			int cnt1 = 0;

			for (int i = 0; i < n; i++) {
				if (bottoms[i] == a) {
					continue;
				}

				cnt1++;
			}

			val1 = min(cnt, cnt1);

		} else {
			val1 = INT_MAX;
		}

		if (b != -1) {
			val2 = 0;

			int cnt = 0;

			for (int i = 0; i < n; i++) {
				if (tops[i] == b) {
					continue;
				}

				cnt++;
			}

			int cnt1 = 0;

			for (int i = 0; i < n; i++) {
				if (bottoms[i] == b) {
					continue;
				}

				cnt1++;
			}

			val2 = min(cnt, cnt1);
		} else {
			val2 = INT_MAX;
		}

		return min(val1, val2);
	}
};