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
	char findTheDifference(string s, string t) {

		vector<int> v_s(26, 0);
		vector<int> v_t(26, 0);

		for (auto ch : s) {

			v_s[ch - 'a']++;
		}

		for (auto ch : t) {
			v_t[ch - 'a']++;
		}

		char ans = ' ';

		for (int i = 0; i < 26; i++) {
			int d = abs(v_s[i] - v_t[i]);

			if (d == 1) {
				ans = 'a' + i;
				break;
			}
		}

		return ans;
	}
};