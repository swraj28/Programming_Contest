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

// bool ok = true;

// void dfs(ll src, vector<ll> gr[], vector<ll> &pos) {

// 	ll mn = INT_MAX;

// 	for (auto nbr : gr[src]) {
// 		dfs(nbr, gr, pos);
// 		mn = min(mn, pos[nbr]);
// 	}

// 	if (mn < pos[src]) {
// 		ok = false;
// 		return;
// 	}
// }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector<ll> v(n + 1);
		vector<ll> p(n + 1);

		for (ll i = 1; i <= n; i++) {
			cin >> v[i];
		}

		vector<ll> pos(n + 1);

		for (ll i = 1; i <= n; i++) {
			cin >> p[i];
			pos[p[i]] = i;
		}

		ll src = -1;

		vector<ll> gr[n + 1]; //  We will construct a directed graph

		vector<ll> parent(n + 1);

		for (ll i = 1; i <= n; i++) {
			if (i == v[i]) {
				src = i;
			} else {
				gr[v[i]].pb(i);
				parent[i] = v[i];
			}
		}

		if (src != p[1]) {
			cout << -1 << endl;
			continue;
		}

		// dfs(src, gr, pos);

		// if (ok == false) {
		// 	cout << -1 << endl;
		// 	ok = true;
		// 	continue;
		// }

		vector<ll> wt(n + 1);

		wt[src] = 0;

		vector<ll> dist((n + 1), -1);

		dist[src] = 0;

		bool f = true;

		for (ll i = 2; i <= n; i++) {

			if (dist[parent[p[i]]] == -1) {
				f = false;
				break;
			}

			dist[p[i]] = (i - 1);

			wt[p[i]] = (dist[p[i]] - dist[parent[p[i]]]);
		}

		if (f) {
			for (ll i = 1; i <= n; i++) {
				cout << wt[i] << " ";
			}
			cout << endl;
		} else {
			cout << -1 << endl;
		}
	}

	return 0;
}