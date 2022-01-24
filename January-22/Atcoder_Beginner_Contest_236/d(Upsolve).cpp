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
    Since it is mandatory to pair all the people. (N pairs must be created)

    Let us suppose N=5.

    for example-> to pair the 7th person we have only 3 options (7,8),(7,9) and (7,10).
                  If somehow we have already used the persons 8,9 and 10 to pair with some other persons then 7 cannot be paired
                  with anyone and this is not a valid way. Therefore we need to backtrack and perform differnt pairing.
*/

ll mx = LLONG_MIN;

void dfs(ll s1, ll s2, ll n, vector<pair<ll, ll>> gr[], vector<ll> &visited, ll ans) {

	visited[s1] = 1;
	visited[s2] = 1;

	ll src = 1;

	while (src < (2 * n) and visited[src] == 1) {
		src++;
	}

	if (src == 2 * n) {
		mx = max(mx, ans);
		return;
	}

	for (auto nbr : gr[src]) {

		if ((!visited[nbr.ff])) {
			dfs(src, nbr.ff, n, gr, visited, (ans ^ nbr.ss));

			visited[src] = visited[nbr.ff] = 0;  // Backtracking
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll n;
	cin >> n;

	vector<pair<ll, ll>> gr[(2 * n) + 1];

	for (ll i = 1; i < (2 * n); i++) {
		for (ll j = i + 1; j <= (2 * n); j++) {
			ll x;
			cin >> x;
			gr[i].pb({j, x});
		}
	}

	// for (ll i = 1; i <= (2 * n); i++) {
	// 	cout << i << "->";
	// 	for (auto p : gr[i]) {
	// 		cout << "{" << p.ff << " " << p.ss << "}" << " ";
	// 	}
	// 	cout << endl;
	// }

	// cout << endl;

	for (auto ele : gr[1]) {

		vector<ll> visited((2 * n) + 1, 0);

		dfs(1, ele.ff, n, gr, visited, (0 ^ ele.ss));
	}

	cout << mx << endl;

	return 0;
}