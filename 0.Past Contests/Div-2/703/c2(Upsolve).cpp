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

	bool recur(string s, int n, int si, int minJump, int maxJump) {

		if (si == (n - 1)) {
			return true;
		}

		int l = si + minJump;
		int r = min({si + maxJump, n - 1});

		for (int i = l; i <= r; i++) {
			if (s[i] == '0') {

				bool rec_res = recur(s, n, i, minJump, maxJump);

				if (rec_res == true) {
					return true;
				}
			}
		}

		return false;
	}

	bool canReach(string s, int minJump, int maxJump) {

		int n = s.length();

		// return recur(s, n, 0, minJump, maxJump);

		int st = 0;


	}
};