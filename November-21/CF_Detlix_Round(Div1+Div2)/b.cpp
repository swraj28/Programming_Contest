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

	int n, q;
	cin >> n >> q;

	string s;
	cin >> s;

	unordered_set<int> pos;

	if (n < 3) {
		while (q--) {
			int p;
			char ch;
			cin >> p >> ch;
			cout << 0 << endl;
		}

		return 0;
	}

	for (int i = 0; i <= (n - 3); i++) {

		char a = s[i], b = s[i + 1], c = s[i + 2];
		string x = "";

		x += a;
		x += b;
		x += c;

		if (x == "abc") {
			pos.insert(i);
		}
	}

	while (q--) {

		int p;
		char ch;
		cin >> p >> ch;

		p--;

		if (s[p] == ch) {
			cout << pos.size() << endl;
			continue;
		}

		if (pos.find(p) != pos.end()) {
			s[p] = ch;
			pos.erase(p);
			s[p] = ch;

			string x = "";

			if (ch == 'a') {
				x += ch;
				if ((p + 1) < n and s[p + 1] == 'b') {
					x += 'b';
				}
				if ((p + 2) < n and s[p + 2] == 'c') {
					x += 'c';
				}
				if (x == "abc") {
					pos.insert(p);
				}

				cout << pos.size() << endl;

			} else if (ch == 'b') {
				if ((p - 1) >= 0 and s[p - 1] == 'a') {
					x += 'a';
				}

				x += 'b';

				if ((p + 1) < n and s[p + 1] == 'c') {
					x += 'c';
				}

				if (x == "abc") {
					pos.insert(p - 1);
				}

				cout << pos.size() << endl;
			} else if (ch == 'c') {
				if ((p - 2) >= 0 and s[p - 2] == 'a') {
					x += 'a';
				}
				if ((p - 1) >= 0 and s[p - 1] == 'b') {
					x += 'b';
				}
				x += 'c';

				if (x == "abc") {
					pos.insert(p - 2);
				}

				cout << pos.size() << endl;
			}
			// cout << pos.size() << endl;
		} else {

			int z = (p - 1), y = (p - 2);

			if (pos.find(z) != pos.end()) {
				pos.erase(z);
			}

			if (pos.find(y) != pos.end()) {
				pos.erase(y);
			}

			s[p] = ch;

			string x = "";

			if (ch == 'a') {
				x += ch;
				if ((p + 1) < n and s[p + 1] == 'b') {
					x += 'b';
				}
				if ((p + 2) < n and s[p + 2] == 'c') {
					x += 'c';
				}
				if (x == "abc") {
					pos.insert(p);
				}

				cout << pos.size() << endl;

			} else if (ch == 'b') {
				if ((p - 1) >= 0 and s[p - 1] == 'a') {
					x += 'a';
				}

				x += 'b';

				if ((p + 1) < n and s[p + 1] == 'c') {
					x += 'c';
				}

				if (x == "abc") {
					pos.insert(p - 1);
				}

				cout << pos.size() << endl;
			} else if (ch == 'c') {
				if ((p - 2) >= 0 and s[p - 2] == 'a') {
					x += 'a';
				}
				if ((p - 1) >= 0 and s[p - 1] == 'b') {
					x += 'b';
				}
				x += 'c';

				if (x == "abc") {
					pos.insert(p - 2);
				}

				cout << pos.size() << endl;
			}
		}
	}

	return 0;
}