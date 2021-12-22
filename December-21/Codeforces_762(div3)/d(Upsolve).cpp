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
		int m, n;
		cin >> m >> n;

		int arr[m][n] = {};

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		if (n == 2) {
			int val = INT_MIN;

			for (int i = 0; i < m; i++) {
				int v1 = INT_MAX;
				for (int j = 0; j < n; j++) {
					v1 = min(v1, arr[i][j]);
				}

				val = max(val, v1);
			}

			cout << val << endl;
			continue;
		}

		vector<pair<int, int>> v;

		int mx = INT_MIN;

		int mn = 0;

		int idx1 = -1, idx2 = -1;

		// According to peigon hole principle Two friends gifts needs to be bought from a single shop.

		for (int i = 0; i < m; i++) {
			v.clear();

			for (int j = 0; j < n; j++) {
				v.pb({arr[i][j], j});
			}

			sort(all(v), greater<pair<int, int>>());

			int overall_max = min({v[0].ff, v[1].ff});

			if (overall_max > mx) {
				mx = overall_max;
				idx1 = v[0].ss;
				idx2 = v[1].ss;
				mn = min({v[0].ff, v[1].ff});
			}
		}

		// Now we have (n-2) friends left and the number of shops that we can visit is also (n-2).

		for (int j = 0; j < n; j++) {
			if ((j == idx1) or (j == idx2)) {
				continue;
			}

			int mx1 = 0;

			for (int i = 0; i < m; i++) {
				mx1 = max(mx1, arr[i][j]);
			}

			mn = min(mn, mx1);
		}

		cout << mn << endl;
	}

	return 0;
}