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
	int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {

		int n = tires.size();

		vector<ll> without_change(18, (1e16)); // If we choose the smallest value of r (i.e., 2) then as well (int)pow(2,17)>(1e5) && changeTime<=(1e5)

		without_change[0] = 0ll;

		int threshold_value = (1 << 17); // If the cost of the lap exceeds this particular then we need to change the tire to minimize the time.


		for (auto t : tires) {

			int f = t[0], r = t[1];

			ll total = 0;

			for (int i = 1; i <= 17; i++) {

				ll lap_cost = f * (ll)pow(r, (i - 1));

				total = (total + (ll) lap_cost);

				if (total > threshold_value) {
					break;
				}

				without_change[i] = min({without_change[i], total});
			}
		}

		vector<ll> dp(numLaps + 1, (1e16));

		dp[0] = 0;

		for (int i = 1; i <= numLaps; i++) {
			if (i <= 17) {
				dp[i] = without_change[i];
			}

			for (int j = 1; j < i; j++) {
				dp[i] = min({dp[i], dp[j] + changeTime + dp[i - j]});
			}
		}

		return (int)dp[numLaps];
	}
};