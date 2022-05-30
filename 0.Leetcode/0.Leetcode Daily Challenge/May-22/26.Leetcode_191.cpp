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
#define bct(x) __builtin_popcountll(x)

// Approach 1:- Using Inbuit Function:-
class Solution {
public:
	int hammingWeight(uint32_t n) {

		return bct(n);
	}
};

// Approach 2:-

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int cnt = 0; // count of set bit
		while (n > 0) { // iterate until all bits are traversed
			if ((n & 1) > 0) { // check the parity of first bit from right
				++cnt;
			}
			n = n >> 1; //n=n/2, shift one bit to right
		}
		return cnt;
	}
};

// Approach 3:-

class Solution {
public:
	int hammingWeight(uint32_t n) {

		int cnt = 0; // count of set bit

		while (n > 0) { // iterate until all bits are traversed
			++cnt;
			n = n & (n - 1); // change the first set bit from right to 0
		}

		return cnt;
	}
};