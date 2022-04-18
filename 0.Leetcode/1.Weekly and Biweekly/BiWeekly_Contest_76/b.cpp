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
	long long waysToBuyPensPencils(int total, int cost1, int cost2) {

		ll ans = 0;

		ll cnt = 0;

		while ((cnt * (ll)cost1) <= total) {

			ll rem_cost = total - (cnt * (ll)cost1);

			if (rem_cost == 0) {
				ans++;
				break;
			}

			ans += (ll) (rem_cost / cost2);
			ans += 1;

			cnt++;
		}

		return ans;
	}
};