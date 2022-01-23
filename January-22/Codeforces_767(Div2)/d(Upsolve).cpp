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

bool is_pailendrome(string s) {

	int n = s.length();
	int st = 0, end = (n - 1);

	while (st <= end) {
		if (s[st] != s[end]) {
			return false;
		}

		st++, end--;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<string> v;

		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			v.pb(s);
		}

		bool f = false;

		for (int i = 0; i < n; i++) {
			if (is_pailendrome(v[i])) {
				f = true;
				break;
			}
		}

		if (f) {
			YES;
			continue;
		}

		map<string, set<int>> m;

		for (int i = 0; i < n; i++) {
			m[v[i]].insert(i);
		}

		for (int i = 0; i < n; i++) {

			string x = v[i];
			int len = x.length();
			if (len == 2) {
				string b = "";
				b += x[1];
				b += x[0];

				if (m.find(b) != m.end()) {
					auto itr = m[b].lower_bound(i);
					if (itr != m[b].end()) {
						f = true;
						break;
					}
				}

				for (int j = 0; j < 26; j++) {
					char ch = 'a' + j;

					string a = "";
					a += ch;
					a += b;

					if (m.find(a) != m.end()) {
						auto itr = m[a].lower_bound(i);
						if (itr != m[a].end()) {
							f = true;
							break;
						}
					}
				}

				if (f) {
					break;
				}

			} else {
				string a = "", b = "";
				a += x[1];
				a += x[0];

				b += x[2];
				b += x[1];
				b += x[0];

				if (m.find(a) != m.end()) {
					auto itr = m[a].lower_bound(i);
					if (itr != m[a].end()) {
						f = true;
						break;
					}
				}

				if (m.find(b) != m.end()) {
					auto itr = m[b].lower_bound(i);
					if (itr != m[b].end()) {
						f = true;
						break;
					}
				}
			}
		}

		if (f) {
			YES;
		} else {
			NO;
		}
	}

	return 0;
}