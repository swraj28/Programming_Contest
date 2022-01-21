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

/*

     Whenever we are given a circular array try to run the loop not only for n times but for (2*n) times.

*/

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

		int n = gas.size();

		int diff = 0, cnt = 0;

		for (int i = 0; i < 2 * n; i++) {
			diff += (gas[i % n] - cost[i % n]);

			cnt += 1;

			if (diff < 0) {
				diff = 0;
				cnt = 0;
			}

			if (cnt == n) {
				return i;
			}
		}

		return -1;
	}
};