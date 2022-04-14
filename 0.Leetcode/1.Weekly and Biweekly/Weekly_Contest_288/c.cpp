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
	int maximumProduct(vector<int>& nums, int k) {

		int n = nums.size();

		priority_queue<int, vector<int>, greater<int>>pq;

		for (int i = 0; i < n; i++) {
			pq.push(nums[i]);
		}

		while (k--) {

			auto f = pq.top();
			pq.pop();

			f += 1;

			pq.push(f);
		}

		ll ans = 1;

		while (!pq.empty()) {

			auto f = pq.top();
			pq.pop();
			ans *= f;
			ans %= mod;
		}

		return (int)ans;
	}
};