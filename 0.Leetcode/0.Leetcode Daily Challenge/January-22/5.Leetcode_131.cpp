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

	bool is_pailendrome(string s) {

		int n = s.length();
		int st = 0, end = (n - 1);

		while (st <= end) {
			if (s[st] != s[end]) {
				return false;
			}
			st++, end--;
		}

		return true;
	}

	vector<vector<string>> ans;

	void dfs(string s, int si, int n, vector<string> &v) {
		if (si >= n) {
			ans.pb(v);
			return;
		}

		for (int i = si; i < n; i++) {

			string x = s.substr(si, ((i - si) + 1));

			if (is_pailendrome(x)) {
				v.pb(x);
				dfs(s, i + 1, n, v);
				v.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string s) {

		vector<string> v;

		dfs(s, 0, s.length(), v);

		return ans;
	}
};