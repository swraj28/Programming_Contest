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
	long long minimumTime(vector<int>& time, int totalTrips) {

		int n = time.size();

		ll ans = 0;

		for (int i = 0; i < n; i++) {
			ans += (ll)(time[i] * (ll)totalTrips);
		}

		ll st = 1, end = (1e9);

		while (st <= end) {

			ll mid = (st + (ll) (end - st) / 2);

			ll x = 0;

			for (int i = 0; i < n; i++) {
				x += (ll)(mid / (ll) time[i]);
			}

			if (x >= totalTrips) {
				ans = min({ans, mid});
				end = mid - 1;
			} else {
				st = mid + 1;
			}
		}

		return ans;
	}
};