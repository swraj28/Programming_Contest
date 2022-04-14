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
	string minimizeResult(string expression) {

		int n = expression.length();

		int idx = -1;

		for (int i = 0; i < n; i++) {
			if (expression[i] == '+') {
				idx = i;
				break;
			}
		}

		int mn = INT_MAX;
		string ans = "";

		for (int st = idx - 1; st >= 0; st--) {
			for (int end = idx + 1; end < n; end++) {

				int val = 0;

				val += stoi(expression.substr(st, (idx - st)));
				val += stoi(expression.substr(idx + 1, (end - (idx + 1) + 1)));

				string x = "", y = "";

				for (int i = 0; i < st; i++) {
					x += expression[i];
				}

				for (int i = end + 1; i < n; i++) {
					y += expression[i];
				}

				if (x != "") {
					val *= stoi(x);
				}

				if (y != "") {
					val *= stoi(y);
				}

				if (val < mn) {
					mn = val;

					ans = "";

					for (int i = 0; i < st; i++) {
						ans += expression[i];
					}
					ans += '(';

					for (int i = st; i <= end; i++) {
						ans += expression[i];
					}
					ans += ')';

					for (int i = end + 1; i < n; i++) {
						ans += expression[i];
					}
				}
			}
		}

		return ans;
	}
};