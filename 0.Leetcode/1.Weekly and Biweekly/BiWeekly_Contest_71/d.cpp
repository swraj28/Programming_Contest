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
	long long minimumDifference(vector<int>& nums) {

		ll m = nums.size();

		ll n = (m / 3);

		priority_queue<ll, vector<ll>, greater<ll>> pq;

		vector<ll> dp(m, (1e12));

		ll sm = 0;

		ll cnt = 0;

		for (ll i = m - 1; i >= n; i--) {
			sm += (ll)nums[i];
			pq.push(nums[i]);

			cnt++;

			if (cnt > n) {
				cnt--;
				sm -= pq.top();
				pq.pop();

				dp[i] = sm;
			}

			if (cnt == n) {
				dp[i] = sm;
			}
		}

		priority_queue<ll> pq1;

		sm = 0;
		cnt = 0;

		for (ll i = 0; i < (m - n); i++) {
			sm += (ll)nums[i];
			pq1.push(nums[i]);

			cnt++;

			if (cnt > n) {
				cnt--;
				sm -= pq1.top();
				pq1.pop();

				dp[i] = (sm - dp[i + 1]);
			}

			if (cnt == n) {
				dp[i] = (sm - dp[i + 1]);
			}
		}

		ll mn = (1e12);

		for (ll i = 0; i < (m - n); i++) {
			mn = min(mn, dp[i]);
		}

		return mn;
	}
};