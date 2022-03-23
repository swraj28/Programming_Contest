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
	int brokenCalc(int startValue, int target) {

		if (startValue >= target) {
			return (startValue - target);
		}

		int cnt = 0;

		while (target > startValue) {

			if (target % 2) {
				target -= 1;
			} else {
				target /= 2;
			}

			cnt++;
		}

		cnt += abs(target - startValue);

		return cnt;
	}
};