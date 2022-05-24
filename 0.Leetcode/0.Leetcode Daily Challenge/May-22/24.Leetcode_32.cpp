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
	int longestValidParentheses(string s) {

		int n = s.length();

		vector<int> v;

		int ans = 0;

		for (int i = 0; i < n; i++) {
			if (s[i] == '(') {
				v.pb(i);
			} else {
				if ((int)v.size() == 0) {
					v.pb(i);
				} else {
					if (s[v.size() - 1] == '(') {
						v.pop_back();
					} else {
						v.pb(i);
					}
				}
			}
		}

		if ((int)v.size() == 0) {
			ans = n;
		} else {
			for (int i = 1; i < v.size(); i++) {
				ans = max(ans, (v[i] - v[i - 1]) - 1);
			}

			ans = max(ans, (v[0] - 0));
			ans = max(ans, ((n - 1) - v[v.size() - 1]));
		}

		return ans;
	}
};