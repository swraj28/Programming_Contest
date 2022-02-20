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
#define pii pair<int,int>
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
		int n;
		cin >> n;
		mk(arr, n, int);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		if (n <= 2 || is_sorted(arr, arr + n)) {
			cout << 0 << endl;
			for (int i = 0; i < n; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;

			continue;
		}

		vector<int> pos;

		for (int i = 1; i < n - 1;) {

			if ((arr[i] > arr[i - 1]) && (arr[i] > arr[i + 1])) {
				pos.pb(i);
				i += 2;
			} else {
				i += 1;
			}
		}

		// cout << "***************" << endl;

		// for (auto ele : pos) {
		// 	cout << ele << " ";
		// }
		// cout << endl;

		// cout << "*******************" << endl;

		int cnt = 0;

		vector<int> v;

		for (int i = 0; i < pos.size();) {

			if ((i + 1) < pos.size()) {
				int d = pos[i + 1] - pos[i];
				if (d == 2) {
					v.pb(pos[i] + 1);
					cnt++;
					i += 2;
				} else {
					cnt++;
					v.pb(pos[i]);
					i += 1;
				}
			} else {
				cnt++;
				v.pb(pos[i]);
				i += 1;
			}
		}

		// cout << "***************" << endl;

		// for (auto ele : v) {
		// 	cout << ele << " ";
		// }
		// cout << endl;

		// cout << "*******************" << endl;

		for (int i = 0; i < v.size(); i++) {
			int x = max({arr[v[i] - 1], arr[v[i] + 1]});

			arr[v[i]] = x;
		}

		cout << cnt << endl;

		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	return 0;
}