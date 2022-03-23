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
	string getSmallestString(int n, int k) {

		string ans(n, 'a');

		int left = (k - n);

		int idx = (n - 1);

		while (left > 0) {

			left += 1;

			if (left > 26) {
				ans[idx] = 'z';

				left -= 26;
			} else {
				ans[idx] = ((left - 1) + 'a');
				left = 0;
			}

			idx -= 1;
		}

		return ans;
	}
};