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

	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		map<ll, ll> cnt;

		multiset<ll> s;

		for (ll i = 0; i < n; i++) {
			ll x;
			cin >> x;
			cnt[x]++;
			s.insert(x);
		}

		vector<ll> ans(n + 1, 0);

		// It can be observed that if i can't make a mex at (i) then it is not possible to make mex at any (j>i).

		// To make a mex i we need at least (i) elements in the array.

		// It is quite intitutive to observe that that increasing the all the zeros by 1 will get us the mex equal to 1.

		// ans[i] contains minimum number of operations to make mex equals to i.

		// To make mex equals to i--> we require to make mex 0,1,2,....,(i-2),(i-1), and incrementing all the value of i by 1.

		// To make mex equals to (i-1)--> we require to make mex 0,1,2,.....(i-3),(i-2), and incrementing all the values of (i-1) by 1.

		// The common Part at i and (i-1) is (ans[i-1]-cnt[i-1])

		// ans[i]=(ans[i-1]-cnt[i-1])+(cnt[i])+ making of the value (i-1).

		//To make (i-1) we can use the smallest value less than or equal to (i-1).

		ans[0] = cnt[0];

		for (ll i = 1; i <= n; i++) {

			ans[i] = (ans[i - 1] - cnt[i - 1]);
			ans[i] += (ll) (cnt[i]);

			auto itr = s.upper_bound(i - 1);

			if (itr == s.begin()) {

				for (ll j = i; j <= n; j++) {
					ans[j] = -1;
				}
				break;
			}

			itr--;

			ans[i] += (ll) ((i - 1) - (*itr));

			s.erase(itr);
		}

		for (ll i = 0; i <= n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}

	return 0;
}