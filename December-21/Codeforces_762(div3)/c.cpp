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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {

		string a, s;
		cin >> a >> s;

		string b = "";

		bool f = true;

		int n = a.length(), m = s.length();

		int i = (n - 1), j = (m - 1);

		while (i >= 0) {

			int x = (a[i] - '0');

			if (j >= 0) {

				int y = s[j] - '0';

				if (y >= x) {

					int d = (y - x);
					b += (d + '0');
					j -= 1;

				} else {

					if ((j - 1) >= 0) {

						int z = s[j - 1] - '0';

						if (z == 0) {
							f = false;
							break;
						}

						y += (10 * z);

						int d = (y - x);

						if (d > 9) {
							f = false;
							break;
						} else {
							b += (d + '0');
							j -= 2;
						}
					} else {

						f = false;
						break;
					}
				}
			} else {
				f = false;
				break;
			}

			i -= 1;
		}

		if (f == false) {
			cout << -1 << endl;
			continue;
		}

		while (j >= 0) {
			b += s[j];
			j--;
		}

		reverse(all(b));

		int idx = 0;

		while (idx < b.size()) {
			if (b[idx] != '0') {
				break;
			}
			idx++;
		}

		b = b.substr(idx);

		cout << b << endl;
	}

	return 0;
}