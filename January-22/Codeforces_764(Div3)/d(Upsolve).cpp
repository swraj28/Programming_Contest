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
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;

		if (k > (n / 2)) {
			cout << 1 << endl;
			continue;
		}

		map<char, int> m;

		for (int i = 0; i < n; i++) {
			m[s[i]]++;
		}

		vector<int> v;

		for (auto i : m) {
			v.pb(i.ss);
		}

		sort(all(v));

		int mn = 0;

		//******************************Even****************************************************

		int e_pair = 0;

		for (auto ele : v) {
			if (ele >= 2) {
				if (ele % 2 == 0) {
					e_pair += (ele / 2);
				} else {
					ele -= 1;
					e_pair += (ele / 2);
				}
			}
		}

		int cnt = (e_pair / k);

		if (cnt) {
			mn += (2 * cnt);

			int total_spare = (2 * cnt * k);

			for (int i = 0; i < v.size(); i++) {

				if (total_spare == 0) {
					break;
				}

				if (v[i] > 1) {
					if (v[i] % 2 == 0) {
						if (total_spare >= v[i]) {
							total_spare -= v[i];
							v[i] = 0;
						} else {
							v[i] -= total_spare;
							total_spare = 0;
						}
					} else {
						if (total_spare >= (v[i] - 1)) {
							total_spare -= (v[i] - 1);
							v[i] = 1;
						} else {
							v[i] -= total_spare;
							total_spare = 0;
						}
					}
				}
			}
		}

		//************************************ Odd ***************************************************

		multiset<int> st;

		for (auto ele : v) {
			if (ele) {
				st.insert(ele);
			}
		}

		v.clear();

		for (auto ele : st) {
			v.pb(ele);
		}

		if (v.size()) {

			cnt = 0;
			for (auto ele : v) {
				cnt += ele;
			}

			if (cnt >= k) {
				mn += 1;
			}
		}

		cout << mn << endl;
	}

	return 0;
}