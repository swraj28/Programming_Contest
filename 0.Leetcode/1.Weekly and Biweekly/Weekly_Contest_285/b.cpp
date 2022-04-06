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
	int countCollisions(string directions) {

		int n = directions.length();

		bool f = false;

		int total = 0;

		int temp_cnt = 0;

		for (int i = 0; i < n; i++) {
			if (directions[i] == 'L') {
				if (temp_cnt > 0) {
					f = true;
					total += (temp_cnt + 1);
					temp_cnt = 0;
				} else if (f) {
					total++;
				}
			} else if (directions[i] == 'S') {
				if (temp_cnt > 0) {
					total += temp_cnt;
					temp_cnt = 0;
				}
				f = true;
			} else {
				temp_cnt++;
			}
		}

		return total;
	}
};