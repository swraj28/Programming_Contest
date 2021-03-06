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

set<int> s;
vector<int> prefix;

int dp[200005][4];

int recur(vector<int> &v, int n, int si, int splits) { // This function will give us minimum extra to be added

	if (si >= n) {
		if (splits == 1) {
			return 2;
		} else if (splits == 2) {
			return 1;
		}

		return 0;
	}

	if (dp[si][splits] != -1) {
		return dp[si][splits];
	}

	if (splits == 2) {

		int l_val = 0, r_val = 0;

		if ((si - 1) >= 0) {
			l_val = prefix[si - 1];
		}

		r_val = prefix[n - 1];

		int val = (r_val - l_val);

		auto itr = s.lower_bound(val);

		int d = (*itr) - val;

		// cout << val << " " << d << endl;

		// return d + recur(v, n, n, 3);

		return d;
	}

	int ans = INT_MAX;

	for (int i = si; i < n; i++) {

		int l_val = 0, r_val = 0;

		if ((si - 1) >= 0) {
			l_val = prefix[si - 1];
		}

		r_val = prefix[i];

		int val = (r_val - l_val);

		auto itr = s.lower_bound(val);

		int d = (*itr) - val;

		int rec_res = d + recur(v, n, i + 1, splits + 1);

		ans = min(ans, rec_res);
	}

	return dp[si][splits] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	const int N = (2e8);

	int st = 0;

	while (pow(2, st) <= N) {
		s.insert(pow(2, st));
		st++;
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		map<int, int> m;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			m[x]++;
		}

		vector<int> v;

		for (auto i : m) {
			v.pb(i.ss);
		}

		n = v.size();

		if (n == 1) {

			int val = v[0];
			auto itr = s.lower_bound(val);

			int d = (*itr) - val;

			cout << (d + 2) << endl;

			continue;
		}

		prefix.clear();

		int sm = 0;

		for (int i = 0; i < n; i++) {
			sm += v[i];
			prefix.pb(sm);
		}

		// for (int i = 0; i < n; i++) {
		// 	cout << prefix[i] << " ";
		// }
		// cout << endl;

		ms(dp, -1);

		// int ans = recur(v, n, 0, 0);

		int ans = min({recur(v, n, 0, 0), 1 + recur(v, n, 0, 1)});

		cout << ans << endl;
	}

	return 0;
}