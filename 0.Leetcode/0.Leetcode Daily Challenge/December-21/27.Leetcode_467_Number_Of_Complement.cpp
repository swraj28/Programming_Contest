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


// Brute Force Solution:-

class Solution {
public:
	int findComplement(int num) {

		if (num == 0) {
			return 1;
		}

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
};

// Optimized ->(One Line Solution)

/*

num          = 00000101
mask         = 11111000
~mask & ~num = 00000010

*/

class Solution {
public:
	int findComplement(int num) {

		int total_bits = (int)(log2(num)) + 1;

		unsigned mask = (~0);

		mask <<= (total_bits - 1);

		return (~mask & ~ num);
	}
};