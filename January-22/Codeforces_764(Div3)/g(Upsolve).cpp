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

// By using Disjoint Set Union

// T.c->O(E)log(V) --> For justification see the notes

const int N = (2e5 + 5);

int parent[N], sz[N];

void make_set(int v) {
	parent[v] = v;
	sz[v] = 1;
}

int find_par(int v) {

	if (v == parent[v]) {
		return v;
	}

	return parent[v] = find_par(parent[v]);
}

void union_sets(int a, int b) {

	a = find_par(a);
	b = find_par(b);

	if (a == b) {
		return ;
	}

	if (a != b) {
		if (sz[a] >= sz[b]) {
			parent[b] = a;
			sz[a] += sz[b];
		} else {
			parent[a] = b;
			sz[b] += sz[a];
		}
	}
}

struct Edge {
	int u, v, weight;

	// Overloading the < operator

	bool operator<(Edge const& other) {
		return (weight < other.weight);
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {


		int n, m;
		cin >> n >> m;  // n-->no. of vertices and m--> no. of edges

		vector<Edge> edges;

		for (int i = 0; i < m; i++) {
			int a, b, w;
			cin >> a >> b >> w;

			edges.push_back({a, b, w});
		}

		int total = (1 << 30) - 1;

		int mask = 0;

		for (int i = 29; i >= 0; i--) {

			for (int i = 1; i <= n; i++) {
				make_set(i);
			}

			int total_component = n;

			int n_mask = mask | (1 << i);

			for (Edge e : edges) {
				if (((e.weight & n_mask) == 0)) {
					if (find_par(e.u) != find_par(e.v)) {
						union_sets(e.u, e.v);
						total_component -= 1;
					}
				}
			}

			if (total_component == 1) {
				mask |= n_mask;
			}
		}

		total ^= mask;

		cout << total << endl;
	}

	return 0;
}