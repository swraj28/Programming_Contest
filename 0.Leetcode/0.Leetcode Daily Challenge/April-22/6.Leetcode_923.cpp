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

// TLE:-

class Solution {
public:
	int threeSumMulti(vector<int>& arr, int target) {

		int n = arr.size();

		sort(all(arr));

		int total = 0;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int x = (arr[i] + arr[j]);
				int req = (target - x);

				int idx_l = lower_bound(arr.begin() + j + 1, arr.end(), req) - arr.begin();
				int idx_u = upper_bound(arr.begin() + j + 1, arr.end(), req) - arr.begin();

				if (idx_l == idx_u) {
					continue;
				}

				total += (idx_u - idx_l);
				total %= mod;
			}
		}

		return total;
	}
};

// Optimized:-

class Solution {
public:
	int threeSumMulti(vector<int>& arr, int target) {

		int n = arr.size();

		vector<int> cnt(102, 0);

		for (int i = 0; i < n; i++) {
			cnt[arr[i]]++;
		}

		ll total = 0;

		for (int i = 0; i <= 100; i++) {
			for (int j = i; j <= 100; j++) {

				int k = target - (i + j);

				if (k < 0 || k > 100) {
					continue;
				}

				if (i == j && j == k) {
					ll x = cnt[i];

					total += (x * (ll) (x - 1) * (x - 2)) / 6;
				} else if (i == j && j != k) {
					int x = cnt[i];
					int y = cnt[k];

					int val1 = (x * (x - 1)) / 2;

					total += (val1 * y);
				} else if (i < j && j < k) {
					int x = cnt[i], y = cnt[j], z = cnt[k];

					total += (x * y * z);
				}

				total %= mod;
			}
		}
		return (int)total;
	}
};