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

/*

     The Key Idea Here is to use the Concept of precomputation:-

     As it is given that for (n=2) we have total of 6 possiblities:-

     Let's analyze the case for (n=3)

     __px|Dx__PX|DX__PX|DX__PX|DX__   ---> If we fixes (p1,d1,p2,d2) (As we have computed it in previous step)

     1. P3__px|Dx__PX|DX__PX|DX__PX|DX__ ---> Total positions to place D3 is 5
     2.   __px|Dx,P3__PX|DX__PX|DX__PX|DX__ ---> The first place get useless as we cannot place D3 there but there are 4 places remaining where we can place D3.

     3. __px|Dx__PX|DX,P3__PX|DX__PX|DX__ --->The first two  place get useless as we cannot place D3 there but there are 3 places remaining where we can place D3
     3. __px|Dx__PX|DX__PX|DX,P3__PX|DX__ --->The first three place get useless as we cannot place D3 there but there are 2 places remaining where we can place D3.
     3. __px|Dx__PX|DX__PX|DX__PX|DX,P3__ --->Now we are left with only one place where we can place D3.

     Therefore dp[3]= (5+4+3+2+1)*dp[2].
*/

class Solution {
public:
	int countOrders(int n) {

		if (n == 1) {
			return 1;
		}

		vector<ll> dp(n + 1, 0ll);

		dp[1] = 1ll;
		dp[2] = 6ll;

		for (int i = 3; i <= n; i++) {

			int pos = (i - 1) * (ll) 2;
			pos += 1;

			int val = (pos * (pos + 1)) / 2;

			dp[i] = ((dp[i - 1] % mod) * (val % mod)) % mod;
		}

		return (int)dp[n];

	}
};