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

// 1. Brute Force

class Solution {
public:
	int findComplement(int num) {

		int ans = 0;
		int bp = 0;

		while (num) {
			if ((num & 1) == 0) {
				ans += pow(2, bp);
			}
			num >>= 1;
			bp++;
		}

		return ans;
	}

	int bitwiseComplement(int n) {
		if (n == 0) return 1;
		return findComplement(n);
	}
};

// 2. Optimized:-

class Solution {
public:
	int bitwiseComplement(int n) {

		if (n == 0) {
			return 1;
		}

		unsigned mask = (~0);

		int total_bits = (int)(log2(n)) + 1;

		mask <<= total_bits;

		return (~mask ^ n);
	}
};