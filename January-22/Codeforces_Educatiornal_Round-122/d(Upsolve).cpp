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

int recur(vector<pair<int, int>> &v, int n, int si, int k, vector<vector<int>> &dp) {
	if (si >= n) {
		return 0;
	}

	if (dp[si][k] != -1) {
		return dp[si][k];
	}

	if (v[si].ff == 0) {
		return dp[si][k] = v[si].ss + recur(v, n, si + 1, k, dp);
	}

	if (k >= v[si].ff) {
		return dp[si][k] = max({v[si].ss + recur(v, n, si + 1, k - v[si].ff, dp), recur(v, n, si + 1, k, dp)});
	}

	return dp[si][k] = recur(v, n, si + 1, k, dp);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<int> cnt(1001, INT_MAX);

	cnt[0] = cnt[1] = 0;

	cnt[2] = 1;

	for (int i = 2; i <= 1000; i++) {

		for (int x = 1; x <= i; x++) {

			int d = i / x;

			int val = i + d;

			if (val <= 1000) {
				cnt[val] = min({cnt[val], cnt[i] + 1});
			}
		}
	}

	int sm = 12000;  // overall sum of the cnt vector is about 10800 which is approximately equal 12000.

	int t;
	cin >> t;
	while (t--) {

		int n, k;
		cin >> n >> k;

		mk(brr, n, int);
		mk(crr, n, int);

		for (int i = 0; i < n; i++) {
			cin >> brr[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> crr[i];
		}

		if (k == 0) {
			int ans = 0;
			for (int i = 0; i < n; i++) {
				if (brr[i] == 1) {
					ans += crr[i];
				}
			}

			cout << ans << endl;
			continue;
		}

		vector<pair<int, int>> v;

		for (int i = 0; i < n; i++) {
			v.pb({cnt[brr[i]], crr[i]});
		}

		k = min(k, sm);

		vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

		cout << recur(v, n, 0, k, dp) << endl;
	}

	return 0;
}