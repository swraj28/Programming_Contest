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
	bool detectCapitalUse(string word) {

		int n = word.length();

		int lower_cnt = 0, upper_cnt = 0;

		for (int i = 0; i < n; i++) {
			if (isupper(word[i]) and lower_cnt > 0) {
				return false;
			}

			if (islower(word[i]) and upper_cnt > 1) {
				return false;
			}

			if (isupper(word[i])) {
				upper_cnt++;
			} else {
				lower_cnt++;
			}
		}

		return true;
	}
};