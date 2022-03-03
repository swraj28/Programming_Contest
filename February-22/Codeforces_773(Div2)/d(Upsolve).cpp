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

/*
        It was more of an observation Question rather than algorithmic Challenge.

        Since we have to create two copies for one element,then if the element count is odd initially then it is not possible to do the
        given Operation.

        At every time we target to reduce our search space by 2 (i.e., Eliminate the first element and its nearest occurance)--> At every step we
        were reducing the search space by 2. Then maximum Operation will be less than equals to n^2.

        // It was very tricky to implement after getting the logic.
*/

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<int> v;

		map<int, int> m;

		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			v.pb(x);
			m[x]++;
		}

		bool f = true;

		for (auto ele : m) {
			if ((ele.ss % 2) == 1) {
				f = false;
				break;
			}
		}

		if (f == false) {
			cout << -1 << endl;
			continue;
		}

		// From Here the answer is possible

		vector<pair<int, int>> v1;
		vector<int> v2;

		int done = 0;

		while (!v.empty()) {

			if (v.size() == 2) {
				v2.pb(2);
				break;
			}

			int cur_ele = v[0];

			int st = 0, end = -1;

			for (int i = 1; i < v.size(); i++) {
				if (v[i] == cur_ele) {
					end = i;
					break;
				}
			}

			vector<int> temp;

			for (int i = st + 1; i < end; i++) {
				temp.pb(v[i]);

				v1.pb({(i - st) + (end + done), v[i]});
			}

			reverse(all(temp));

			for (int i = end + 1; i < v.size(); i++) {
				temp.pb(v[i]);
			}

			v = temp;

			done += (2 * (end - st));

			v2.pb((2 * (end - st)));
		}

		cout << v1.size() << endl;

		for (auto ele : v1) {
			cout << ele.ff << " " << ele.ss << endl;
		}

		cout << v2.size() << endl;

		for (auto ele : v2) {
			cout << ele << " ";
		}
		cout << endl;
	}

	return 0;
}