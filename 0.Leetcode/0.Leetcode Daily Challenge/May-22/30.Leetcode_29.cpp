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

// Division is nothing but repeatitive subtraction

// Brute Froce Implementation:- (Will Lead to TLE)

class Solution {
public:
	int divide(int dividend, int divisor) {

		if ((dividend == INT_MIN) && divisor == -1) {  // Handle the corner case seperately.
			return INT_MAX;
		}

		int sign = (((dividend < 0) ^ (divisor < 0)) == 0) ? +1 : -1;

		ll dividend_1 = abs(dividend);
		ll divisor_1 = abs(divisor);

		if (divisor_1 == 1) {

			ll x = INT_MAX;

			if ((dividend_1 > x) && sign == 1) {
				return INT_MAX;
			} else {
				dividend_1 *= sign;
			}

			return dividend_1;
		}

		int quotient = 0;

		while (dividend_1 >= divisor_1) {
			dividend_1 -= divisor_1;
			quotient++;
		}

		// Here whatever dividend left will be treated as remainder.

		quotient *= sign;

		return quotient;
	}
};

// Optimization:- (Bit Manipulation)

/*

The key observation is that the quotient of a division is just the number of times that
we can subtract the divisor from the dividend without making it negative.

Suppose dividend = 15 and divisor = 3, 15 - 3 > 0.
We now try to subtract more by shifting 3 to the left by 1 bit (6). Since 15 - 6 > 0, shift 6 again to 12. Now 15 - 12 > 0, shift 12 again to 24,
which is larger than 15. So we can at most subtract 12 from 15. Since 12 is obtained by shifting 3 to left twice, it is 1 << 2 = 4 times of 3.
We add 4 to an answer variable (initialized to be 0).
The above process is like 15 = 3 * 4 + 3. We now get part of the quotient (4), with a remaining dividend 3.

Then we repeat the above process by subtracting divisor = 3 from the remaining dividend = 3 and obtain 0.
 We are done. In this case, no shift happens. We simply add 1 << 0 = 1 to the answer variable.

*/

class Solution {
public:
	int divide(int dividend, int divisor) {

		if ((dividend == INT_MIN) && divisor == -1) {  // Handle the corner case seperately.
			return INT_MAX;
		}

		int sign = (((dividend < 0) ^ (divisor < 0)) == 0) ? +1 : -1;

		long long int a = abs(dividend);
		long long int b = abs(divisor);

		long long int quotient = 0;

		while (a >= b) {

			int q = 0;

			while (a > (b << (q + 1))) {
				q++;
			}

			quotient += (1 << q);

			a -= (b << q);
		}

		return quotient * sign;
	}
};