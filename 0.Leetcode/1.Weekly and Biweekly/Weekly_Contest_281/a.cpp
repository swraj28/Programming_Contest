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
	int countEven(int num) {

		int cnt = 0;

		for (int i = 2; i <= num; i++) {
			string x = to_string(i);

			int sm = 0;
			for (auto ch : x) {
				sm += (ch - '0');
			}

			if (sm % 2 == 0) {
				cnt++;
			}
		}

		return cnt;
	}
};