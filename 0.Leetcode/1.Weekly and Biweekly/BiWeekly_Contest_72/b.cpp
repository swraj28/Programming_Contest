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
	vector<long long> sumOfThree(long long num) {

		vector<ll> v;

		if (num % 3) {
			return v;
		}

		num /= 3;

		v.pb(num - 1);
		v.pb(num);
		v.pb(num + 1);

		return v;
	}
};