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
	int minEatingSpeed(vector<int>& piles, int h) {

		int n = piles.size();

		int st = 1, end = (int)(1e9);

		int ans = INT_MAX;

		while (st <= end) {

			int mid = (st + (end - st) / 2);

			int cnt = 0;

			for (int i = 0; i < n; i++) {
				cnt += ceil(piles[i] / (mid * (1.0)));
			}

			if (cnt <= h) {
				ans = min(ans, mid);
				end = mid - 1;
			} else {
				st = mid + 1;
			}
		}

		return ans;
	}
};