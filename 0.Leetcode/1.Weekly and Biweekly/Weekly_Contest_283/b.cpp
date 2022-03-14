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
	long long minimalKSum(vector<int>& nums, int k) {

		int n = nums.size();

		sort(all(nums));

		// for(auto ele:nums){
		//     cout<<ele<<" ";
		// }
		// cout<<endl;

		int st = 1;

		ll sm = 0;

		for (int i = 0; i < n; i++) {
			if (k == 0) {
				break;
			}

			if (nums[i] == st) {
				st = nums[i] + 1;
				continue;
			}

			if (st > nums[i]) {
				st = nums[i] + 1;
				continue;
			}

			int l = st, r = (nums[i] - 1);

			int d = (r - l) + 1;

			if (d == 0) {
				st = nums[i] + 1;
				continue;
			}

			d = min({d, k});

			k -= d;

			r = (l + d) - 1;

			ll val2 = (r * (ll)(r + 1)) / 2;
			ll val1 = (l * (ll)(l - 1)) / 2;

			ll ans = (val2 - val1);
			sm += (ll) ans;

			st = (nums[i] + 1);
		}

		if (k) {

			ll l = st;

			ll r = (l + k) - 1;

			ll val2 = (r * (ll)(r + 1)) / 2;
			ll val1 = (l * (ll)(l - 1)) / 2;

			ll ans = (val2 - val1);
			sm += (ll) ans;
		}

		return sm;
	}
};