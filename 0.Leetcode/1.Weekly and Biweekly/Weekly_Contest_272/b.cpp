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
	string addSpaces(string s, vector<int>& spaces) {

		string ans = "";

		int idx = 0;

		int n = s.length();

		for (int i = 0; i < n; i++) {

			if ((idx < spaces.size()) && spaces[idx] == i) {
				ans += ' ';
				idx++;
				ans += s[i];

				continue;
			}

			ans += s[i];
		}

		return ans;
	}
};