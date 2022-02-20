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
	string repeatLimitedString(string s, int repeatLimit) {

		int n = s.length();

		vector<int> cnt(26, 0);

		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'a']++;
		}

		string ans = "";

		bool f = true;

		int total = 0;

		while (true) {

			if (total == n) {
				break;
			}

			if (f) {
				for (int i = 25; i >= 0; i--) {

					char ch = 'a' + i;

					if (cnt[i] > 0) {

						int temp1 = repeatLimit;

						if (cnt[i] > temp1) {

							cnt[i] -= temp1;

							total += temp1;

							while (temp1--) {
								ans += ch;
							}

							f = false;
							break;
						} else {
							total += cnt[i];

							temp1 = cnt[i];

							cnt[i] = 0;

							while (temp1--) {
								ans += ch;
							}

							break;
						}
					}
				}
			} else {

				int temp = 0;

				for (int i = 25; i >= 0; i--) {
					char ch = 'a' + i;

					if (cnt[i] > 0) {
						temp++;
					}

					if (temp == 2) {
						ans += ch;
						f = true;
						total += 1;
						cnt[i] -= 1;

						break;
					}
				}

				if (temp != 2) {
					break;
				}
			}
		}

		return ans;
	}
};