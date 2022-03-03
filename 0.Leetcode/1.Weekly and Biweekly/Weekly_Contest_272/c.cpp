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
	long long getDescentPeriods(vector<int>& prices) {

		int n = prices.size();

		ll cnt = n;

		ll t_cnt = 1;

		for (int i = 1; i < n; i++) {
			if ((prices[i - 1] - prices[i]) == 1) {
				t_cnt++;
			} else {
				cnt += (t_cnt * (ll)(t_cnt - 1)) / 2;

				t_cnt = 1;
			}
		}

		cnt += (t_cnt * (ll)(t_cnt - 1)) / 2;

		return cnt;
	}
};