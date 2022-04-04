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
	int minBitFlips(int start, int goal) {

		ll x = ((ll)start ^ (ll)goal);

		int cnt = 0;

		while (x) {
			if (x & 1) {
				cnt++;
			}
			x >>= 1;
		}

		return cnt;
	}
};