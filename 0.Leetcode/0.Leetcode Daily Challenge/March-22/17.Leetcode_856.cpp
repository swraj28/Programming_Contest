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
	int scoreOfParentheses(string s) {

		int n = s.length();
		int total = 0;

		vector<int> v;

		int sze = 0;

		for (int i = 0; i < n; i++) {
			if (s[i] == '(') {
				v.pb(0);
				sze++;
			} else {
				if (v[sze - 1] == 0) {
					v.pop_back();
					sze -= 1;
					if (sze > 0) {
						v[sze - 1] += 1;
					} else {
						total += 1;
					}
				} else {
					int x = v[sze - 1];
					v.pop_back();
					sze -= 1;
					if (sze > 0) {
						v[sze - 1] += (2 * x);
					} else {
						total += (2 * x);
					}
				}
			}
		}

		return total;
	}
};