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
	bool validPalindrome(string s) {

		int n = s.length();

		int st = 0, end = n - 1;

		while (st < end) {
			if (s[st] == s[end]) {
				st++, end--;
			} else {

				int st1 = st + 1;
				int end1 = end - 1;

				bool f = true;

				while (st1 < end) {
					if (s[st1] != s[end]) {
						f = false;
						break;
					}
					st1++, end--;
				}

				if (f) {
					return true;
				}

				while (st < end1) {
					if (s[st] != s[end1]) {
						return false;
					}
					st++, end1--;
				}

				return true;
			}
		}

		return true;
	}
};