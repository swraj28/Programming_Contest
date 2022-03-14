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
	vector<string> cellsInRange(string s) {

		int n = 5;

		vector<string> ans;


		for (char ch = s[0]; ch <= s[3]; ch++) {
			for (int val = s[1] - '0'; val <= s[4] - '0'; val++) {
				string a = "";
				a += ch;
				a += to_string(val);

				ans.pb(a);
			}
		}

		return ans;
	}
};