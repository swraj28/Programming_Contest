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
	int maximumCandies(vector<int>& candies, long long k) {

		ll sm = 0;

		for (auto ele : candies) {
			sm += (ll)ele;
		}

		if (sm < k) {
			return 0;
		}

		int n = candies.size();

		sort(all(candies), greater<int>());

		int st = 1, end = candies[0];

		while (st + 1 < end) {

			int mid = (st + (end - st) / 2);

			ll val = k;

			for (int i = 0; i < n; i++) {
				if (val <= 0) {
					break;
				}

				int cnt = (candies[i] / mid);

				if (cnt == 0) {
					break;
				}

				val -= cnt;
			}

			if (val <= 0) {
				st = mid;
			} else {
				end = mid;
			}
		}

		ll val = k;

		for (int i = 0; i < n; i++) {
			if (val <= 0) {
				break;
			}

			int cnt = (candies[i] / end);

			if (cnt == 0) {
				break;
			}

			val -= cnt;
		}

		if (val <= 0) {
			return end;
		}

		return st;
	}
};