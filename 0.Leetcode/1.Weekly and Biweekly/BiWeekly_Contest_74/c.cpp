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

	int halveArray(vector<int>& nums) {

		int n = nums.size();

		ll x = accumulate(all(nums), 0ll);

		double half = (double)x / (2.0);

		int cnt = 0;

		priority_queue<double> pq;

		for (int i = 0; i < n; i++) {
			pq.push((nums[i] * (1.0)));
		}

		while (half > 0) {

			auto f = pq.top();
			pq.pop();

			double x = f / (2.0);
			half -= x;

			f /= (2.0);

			pq.push(f);

			cnt++;
		}

		return cnt;
	}
};