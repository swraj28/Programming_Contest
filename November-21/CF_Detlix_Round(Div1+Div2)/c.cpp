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

	const int N = (1e6 + 5);

	bool arr[N];

	memset(arr, true, sizeof(arr));

	arr[0] = arr[1] = 0;

	for (int i = 2; i * i < N; i++) {
		if (arr[i]) {
			for (int j = (i * i); j < N; j += i) {
				arr[j] = 0;
			}
		}
	}

	ll t;
	cin >> t;
	while (t--) {
		ll n, e;
		cin >> n >> e;

		vector<ll> v(n, 0);

		for (ll i = 0; i < n; i++) {
			cin >> v[i];
		}

		vector<ll> pre(n, 0);
		vector<ll> suff(n, 0);

		for (ll i = 0; i < n; i++) {

			if (v[i] == 1 and pre[i] == 0) {

				ll j = i;
				pre[j] = 1;

				while ((j + e) < n and v[j + e] == 1) {
					pre[j + e] = 1;

					pre[j + e] += pre[j];

					j += e;
				}

				if ((j + e) < n) {
					pre[j + e] = pre[j];
				}
			}
		}

		for (ll i = n - 1; i >= 0; i--) {
			if (v[i] == 1 and suff[i] == 0) {
				ll j = i;
				suff[j] = 1;
				while ((j - e) >= 0 and v[j - e] == 1) {
					suff[j - e] = 1;
					suff[j - e] += suff[j];
					j -= e;
				}

				if ((j - e) >= 0) {
					suff[j - e] = suff[j];
				}
			}
		}

		// for (ll i = 0; i < n; i++) {
		// 	cout << pre[i] << " ";
		// }
		// cout << endl;

		// for (ll i = 0; i < n; i++) {
		// 	cout << suff[i] << " ";
		// }
		// cout << endl;

		ll cnt = 0;

		for (ll i = 0; i < n; i++) {
			if (arr[v[i]]) {
				ll left = pre[i];
				ll right = suff[i];

				cnt += (left + (ll) right + (left * (ll)right));
			}
		}

		cout << cnt << endl;
	}

	return 0;
}