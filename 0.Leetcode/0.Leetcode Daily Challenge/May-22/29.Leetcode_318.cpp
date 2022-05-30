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
	int maxProduct(vector<string>& words) {

		int n = words.size();

		vector<bitset<26>> v(n);  // Use of Bitset

		for (int i = 0; i < n; i++) {

			string s = words[i];

			for (auto ch : s) {

				v[i][ch - 'a'] = 1;
			}
		}

		int mx = 0;

		for (int i = 0; i < n; i++) {
			string a = words[i];

			for (int j = i + 1; j < n; j++) {
				string b = words[j];

				bool f = true;

				for (auto ch : a) {

					if (v[j][ch - 'a'] == 1) {
						f = false;
						break;
					}
				}

				if (f) {
					mx = max(mx, ((int)a.length() + (int)b.length()));
				}
			}
		}

		return mx;
	}
};