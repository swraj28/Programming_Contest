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

// Extra Spac:-

class Solution {
public:
	string minRemoveToMakeValid(string s) {

		int n = s.length();

		unordered_set<int> st;

		vector<int> Stack;

		for (int i = 0; i < n; i++) {
			if (s[i] == '(') {
				Stack.pb(i);
			} else if (s[i] == ')') {
				if ((int)Stack.size() > 0) {
					Stack.pop_back();
				} else {
					st.insert(i);
				}
			}
		}

		for (auto ele : Stack) {
			st.insert(ele);
		}

		string ans = "";

		for (int i = 0; i < n; i++) {
			if (st.find(s[i]) == st.end()) {
				ans += s[i];
			}
		}

		return ans;
	}
};

// Without Extra Spac:-

class Solution {
public:

	string minRemoveToMakeValid(string s) {

		stack<int> st;

		for (auto i = 0; i < s.size(); ++i) {

			if (s[i] == '(') st.push(i);

			if (s[i] == ')') {

				if (!st.empty()) st.pop();

				else s[i] = '*';
			}
		}

		while (!st.empty()) {
			s[st.top()] = '*';
			st.pop();
		}

		s.erase(remove(s.begin(), s.end(), '*'), s.end());

		return s;
	}
};