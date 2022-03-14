#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define PI 3.1415926535897932384626
#define mod 1000000007
#define mod1 998244353
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define deb(x) cout<<x<<"\n";
#define deB(x,y) cout<<x<<" "<<y<<"\n";
#define Deb(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define YES cout<<"YES\n";
#define Yes cout<<"Yes\n";
#define NO cout<<"NO\n";
#define No cout<<"No\n";
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()
#define mk(arr,n,type)  type *arr=new type[n];
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// cout << s.order_of_key(2) << endl; // the number of elements in the s less than 2
// cout << *s.find_by_order(0) << endl; // print the 0-th smallest number in s(0-based)

/*-------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
/*--------------------------------------------------------------------------------------------*/

/*
   Approach:-    Just Express x in terms of power of 'd'. x=(d^c)*y.
   				 1. If (c<2)--> We cannot split 'x' into two parts such that it is divisible by 'd'.

   				 2. If (c==2) -> x=(d*d)*y;
   				 				 a. First Way :- x= (d)* (d*y)
   				 				 b. Second Way :- If (y is a composite number then we can express it differntly )--> (d*y1)* (d*y2)
   				 				 				  If 'y' is a prime number then it is not possible as to make two different representations.

   			     3. If (c==3) ---> x=(d*d*d)*y.
   			                       a. First Way :- x=(d)*(d)*(d*y).
   			                       b. If Y be a composite number :- x= (d)*(d*y1)*(d*y2)
   			                       c. If Y is prime :- Then we can split one of the extra 'd' given that it is composite and and any factor of 'd'
   			                                           when multiplied with 'y' doesnot give any multiple of 'd', Otherwise it is not possible.

   			      4. If (c>=4)---> The only condition where answer is not possible if both 'd' and 'y' are prime or 1.
*/

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		ll x, d;
		cin >> x >> d;

		ll temp = x;
		ll cnt = 0;

		while ((temp % d) == 0) {
			cnt++;
			temp /= d;
		}

		// cout << cnt << " " << temp << endl;

		if (cnt < 2) {
			NO;
			continue;
		}

		ll left = temp;

		ll cnt1 = 0;

		for (ll i = 1; (i * (ll)i) <= left; i++) {
			if (left % i == 0) {

				if (i != (left / i)) {
					cnt1 += 2;
				} else {
					cnt1++;
				}
			}
		}

		if (cnt >= 4) {

			if (cnt1 > 2) {
				YES;
				continue;
			}

			int cnt_d = 0;

			for (ll i = 1; (i * (ll)i) <= d; i++) {
				if (d % i == 0) {

					if (i != (d / i)) {
						cnt_d += 2;
					} else {
						cnt_d++;
					}
				}
			}

			if (cnt_d <= 2) {
				NO;
				continue;
			}

			YES;
			continue;
		}

		// If cnt==2.

		if (cnt == 2) {
			if (cnt1 <= 2) {
				NO;
			} else {
				YES;
			}

			continue;
		}

		// If cnt==3.

		if (cnt1 > 2) {
			YES;
			continue;
		}

		int cnt_d = 0;

		for (ll i = 1; (i * (ll)i) <= d; i++) {
			if (d % i == 0) {

				if (i != (d / i)) {
					cnt_d += 2;
				} else {
					cnt_d++;
				}
			}
		}

		if (cnt_d <= 2) {
			NO;
			continue;
		}


		bool f = false;

		for (ll i = 2; (i * (ll)i) <= d; i++) {
			if (d % i == 0) {

				ll f1 = i, f2 = (d / i);

				ll val1 = (left * (ll) f1), val2 = (left * (ll)f2);

				if ((val1 % d) != 0 || (val2 % d) != 0) {
					f = true;
					break;
				}
			}
		}

		if (f) {
			YES;
		} else {
			NO;
		}
	}

	return 0;
}