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
	int maxScore(vector<int>& cardPoints, int k) {

		int n = cardPoints.size();

		vector<int> pre_sm(n, 0);
		pre_sm[0] = cardPoints[0];

		for (int i = 1; i < n; i++) {
			pre_sm[i] = (pre_sm[i - 1] + cardPoints[i]);
		}

		if (k == n) {
			return pre_sm[n - 1];
		}

		int mx = 0;

		for (int i = 0; i <= k; i++) { // i number of elements from beginning and (k-i) number of elements from the end
			int val = 0;

			if ((i - 1) >= 0) {
				val += pre_sm[i - 1];
			}

			val += (pre_sm[n - 1] - pre_sm[(n - (k - i)) - 1]);

			// cout<<val<<endl;

			mx = max(mx, val);
		}

		return mx;
	}
};