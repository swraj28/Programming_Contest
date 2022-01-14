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
		int n;
		cin >> n;

		vector<int> v;

		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			v.pb(x);
		}

		int mn = *min_element(all(v));

		int mx = (1e9 + 5);

		int st = mn, end = mx;

		vector<int> temp, extra;

		int ans = INT_MIN;

		while (st <= end) {

			int mid = (st + (end - st) / 2);

			temp.clear();
			extra.clear();

			temp = v;

			extra.assign(n, 0);

			for (int i = n - 1; i >= 2; i--) {

				int ex = extra[i];

				int val = (temp[i] + ex);

				if (val > mid) {
					int transfer = (val - mid);

					transfer = min(transfer, temp[i]);

					temp[i] -= transfer;

					int x = (transfer / 3);

					extra[i - 1] += x;
					extra[i - 2] += (2 * x);

					// transfer -= (3 * x);

					// temp[i] += transfer;
				}
			}

			// cout << "****************************************" << endl;

			// cout << mid << endl;

			// for (int i = 0; i < n; i++) {
			// 	cout << temp[i] << " ";
			// }
			// cout << endl;

			// for (int i = 0; i < n; i++) {
			// 	cout << extra[i] << " ";
			// }
			// cout << endl;

			// cout << "*******************************************" << endl;

			int mn1 = INT_MAX;

			for (int i = 0; i < n; i++) {
				int val = (temp[i] + extra[i]);
				mn1 = min(mn1, val);
			}

			if (mn1 >= mid) {
				ans = max(ans, mid);
				st = mid + 1;
			} else {
				end = mid - 1;
			}
		}

		cout << ans << endl;
	}

	return 0;
}