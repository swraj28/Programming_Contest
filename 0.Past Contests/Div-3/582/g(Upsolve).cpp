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

/*

            Use Disjoint Set Union in a smart way:-

*/

ll find_parent(ll v, vector<ll> &parent) {
	if (v == parent[v]) {
		return v;
	}

	return parent[v] = find_parent(parent[v], parent);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll n, m;
	cin >> n >> m;

	vector<pair<ll, pair<ll, ll>>> edges;

	for (ll i = 0; i < (n - 1); i++) {
		ll x, y, w;
		cin >> x >> y >> w;
		edges.pb({w, {x, y}});
	}

	sort(all(edges));

	// for (auto edge : edges) {
	// 	cout << edge.ff << " " << edge.ss.ff << " " << edge.ss.ss << endl;
	// }
	// cout << endl;

	vector<pair<ll, ll>> v;

	for (ll i = 0; i < m; i++) {
		ll x;
		cin >> x;

		v.pb({x, i});
	}

	sort(all(v));

	vector<ll> res(m, 0);


	vector<ll> parent(n + 1);
	vector<ll> sze(n + 1);

	for (ll i = 1; i <= n; i++) {
		parent[i] = i;
		sze[i] = 1;
	}

	ll idx = 0;
	ll ans = 0;
	for (ll i = 0; i < m; i++) {

		while (idx < (n - 1) and edges[idx].ff <= v[i].ff) {

			ll w = edges[idx].ff, a = edges[idx].ss.ff, b = edges[idx].ss.ss;

			a = find_parent(a, parent);
			b = find_parent(b, parent);

			if (sze[a] >= sze[b]) {

				ans += (sze[a] * (ll) sze[b]);

				parent[b] = a;
				sze[a] += sze[b];
			} else {
				ans += (sze[a] * (ll) sze[b]);
				parent[a] = b;
				sze[b] += sze[a];
			}

			idx++;
		}

		res[v[i].ss] = ans;
	}

	for (ll i = 0; i < m; i++) {
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;
}