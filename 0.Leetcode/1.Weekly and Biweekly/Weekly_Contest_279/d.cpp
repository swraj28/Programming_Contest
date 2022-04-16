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
	int minimumTime(string s) {

		int n = s.length();

		int val = 0;

		int ans = INT_MAX;

		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {

				ans = min(ans, (val + (n - i)));

				int x = (i + 1);
				int y = (val + 2);

				val = min(x, y);
			}
		}

		ans = min(ans, val);

		return ans;
	}
};