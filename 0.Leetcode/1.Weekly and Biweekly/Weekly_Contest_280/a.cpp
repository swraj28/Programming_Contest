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
	int countOperations(int num1, int num2) {

		int cnt = 0;

		while (num1 > 0 && num2 > 0) {
			cnt++;
			if (num1 >= num2) {
				num1 -= num2;
			} else {
				num2 -= num1;
			}
		}

		return cnt;
	}
};