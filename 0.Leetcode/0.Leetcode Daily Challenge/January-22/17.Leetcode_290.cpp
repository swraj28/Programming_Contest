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

/*

      Consider this Case during the Implementation:-

                        Pattern--> "abba"
                        String s--> "dog dog dog dog"
*/

class Solution {
public:
	bool wordPattern(string pattern, string s) {

		int n = s.length(), m = pattern.length();
		int idx = 0;

		map<char, string> m1;

		map<string, char> m2;

		string ans = "";

		for (int i = 0; i < n; i++) {
			if (s[i] == ' ') {

				if (idx >= m) {
					return false;
				}

				if (m1.find(pattern[idx]) == m1.end() and m2.find(ans) == m2.end()) {
					m1[pattern[idx]] = ans;
					m2[ans] = pattern[idx];
					ans = "";
					idx++;
				} else {

					string temp = m1[pattern[idx]];

					if (temp != ans) {
						return false;
					}

					char ch = m2[ans];

					if (ch != pattern[idx]) {
						return false;
					}

					ans = "";
					idx++;
				}
			} else {
				ans += s[i];
			}
		}

		if (idx >= m) {
			return false;
		}

		if (m1.find(pattern[idx]) == m1.end() and m2.find(ans) == m2.end()) {
			idx++;
			if (idx < m) {
				return false;
			}
			return true;
		}

		string temp = m1[pattern[idx]];

		if (temp != ans) {
			return false;
		}

		char ch = m2[ans];

		if (ch != pattern[idx]) {
			return false;
		}

		idx++;

		if (idx < m) {
			return false;
		}

		return true;
	}
};