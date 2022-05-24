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

// Brute Force:-

class Solution {
public:
	bool backspaceCompare(string s, string t) {

		string a = "", b = "";

		for (auto ch : s) {
			if (ch == '#') {
				if (a == "") {
					continue;
				}

				a.pop_back();
			} else {
				a += ch;
			}
		}

		for (auto ch : t) {
			if (ch == '#') {
				if (b == "") {
					continue;
				}

				b.pop_back();
			} else {
				b += ch;
			}
		}

		return (a == b);
	}
};

// Optimized:-

