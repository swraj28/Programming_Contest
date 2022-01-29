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
       Key Observations:-

       1. If Overall Xor is Zero then answer is always possible as we can partion the tree into two components definately
       	  as both components will have same value.

       2. If Overall Xor is non- zero:-
       		---> if(k<=2)--> Not Possible (Minimum 3 components are required to obtain a non zero xor).
            -->If we be able to partition the entrie tree into three commponets having same xor then answer is always possible.
*/

void dfs(int src, int par, vector<int> gr[], vector<int> &v, vector<int> &dp, int overall_xor, int &dfs_cnt) {

	dp[src] = v[src];

	for (auto nbr : gr[src]) {
		if (nbr != par) {
			dfs(nbr, src, gr, v, dp, overall_xor, dfs_cnt);

			dp[src] ^= dp[nbr];
		}
	}

	if (dp[src] == overall_xor) {
		dfs_cnt++;
		dp[src] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> v(n + 1);

		int overall_xor = 0;

		for (int i = 1; i <= n; i++) {
			cin >> v[i];
			overall_xor ^= v[i];
		}

		vector<int> gr[n + 1];

		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;

			gr[x].pb(y);
			gr[y].pb(x);
		}

		if (overall_xor == 0) {
			YES;
		} else {

			if (k <= 2) {
				NO;
				continue;
			}

			int dfs_cnt = 0;

			vector<int> dp(n + 1, 0);

			dfs(1, 0, gr, v, dp, overall_xor, dfs_cnt);

			if (dfs_cnt <= 2) {
				NO;
			} else {
				YES;
			}
		}
	}

	return 0;
}