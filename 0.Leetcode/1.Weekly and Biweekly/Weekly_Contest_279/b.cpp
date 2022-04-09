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
	long long smallestNumber(long long num) {

		string s = to_string(num);

		if (s[0] == '-') {
			sort(s.begin() + 1, s.end(), greater<char>());
		} else {
			sort(all(s));
		}


		if (s[0] == '0') {
			if (num > 0) {
				int idx = 0;
				while (idx < (int)s.length()) {
					if (s[idx] != '0') {
						break;
					}
					idx++;
				}

				swap(s[0], s[idx]);
			}
		}

		num = stoll(s);

		return num;
	}
};