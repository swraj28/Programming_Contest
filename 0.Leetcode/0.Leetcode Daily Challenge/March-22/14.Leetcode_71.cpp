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
	string simplifyPath(string path) {

		int n = path.length();

		vector<string> tokens;

		string temp = "";

		for (int i = 0; i < n; i++) {
			if (path[i] != '/') {
				temp += path[i];
			} else {
				if (temp == "") {
					continue;
				}

				tokens.pb(temp);
				temp = "";
			}
		}

		if (temp != "") {
			tokens.pb(temp);
		}

		vector<string> s;

		for (auto token : tokens) {
			if (token == "..") {
				if ((int)s.size() > 0) {
					s.pop_back();
				}
			} else if (token == ".") {
				continue;
			} else {
				s.push_back(token);
			}
		}

		string ans = "/";

		for (auto ele : s) {
			ans += ele;
			ans += "/";
		}

		if (ans.length() > 1) {
			ans.pop_back();
		}

		return ans;
	}
};