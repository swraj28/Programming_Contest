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
	int myAtoi(string s) {

		int n = s.length();

		bool neg = false;
		bool dig = false;

		bool po = false;

		string ans = "";

		for (int i = 0; i < n; i++) {
			if (s[i] == ' ') {
				if (dig) {
					break;
				}
				continue;
			}

			if (s[i] == '-') {
				if (neg) {
					break;
				}
				if (dig) {
					break;
				}

				if ((i + 1 < n) and isdigit(s[i + 1])) {
					neg = true;
					continue;
				}
			}

			if (s[i] == '+') {
				if (po) {
					break;
				}

				if (dig) {
					break;
				}

				if ((i + 1 < n) and isdigit(s[i + 1])) {
					po = true;
					continue;
				}
			}

			if (isdigit(s[i]) == false) {
				break;
			}

			if (isdigit(s[i])) {
				if (dig == false) {
					dig = true;
				}
				ans += s[i];
			}
		}

		ll l = -2147483648;
		ll r = 2147483647;

		bool f = false;

		int idx = 0;
		while (idx < ans.length()) {
			if (ans[idx] != '0') {
				break;
			}
			idx++;
		}

		ans = ans.substr(idx);

		if (neg) {
			int pos = 0;
			ll temp = 0;
			for (int i = ans.length() - 1; i >= 0; i--) {
				temp += (pow(10, pos)) * (ans[i] - '0');

				ll x = (-temp);

				if (x < l or pos >= 10) {
					return (int)l;
				}
				pos++;
			}

			temp = (-temp);
			return (int)temp;
		}

		int pos = 0;
		ll temp = 0;
		for (int i = ans.length() - 1; i >= 0; i--) {
			temp += (pow(10, pos)) * (ans[i] - '0');

			if (temp > r or pos >= 10) {
				return r;
			}

			pos++;
		}

		return (int)temp;
	}
};