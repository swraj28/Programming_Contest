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
     Key Idea:-

     Actually we need to find wheather the floor(x/y)=r, is present the array for every value of x,y where x>=y

     Observation :-

     (x/y)=1 -> x->[y,2*y-1]
     (x/y)=2 -> x->[2*y,3*y-1]
     (x/y)=3 -> x->[3*y,4*y-1]
     .
     .
     (x/y)=k -> x->[k*y,(k+1)*y-1]

     It is given that that every element in the array will be less than or equal to 'c'.

     Therefore y can vary from (1 to c) and similarly (x/y) will also vary upto c.

     Let (x/y)=r.

     As we can see from the above observation, the value of x is present in range. so we can use prefix sum or suffix sm to store the count of the
     value of x for all possible range.
*/

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {

		int n, c;
		cin >> n >> c;

		mk(arr, n, int);
		vector<int> cnt(c + 1, 0);

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			cnt[arr[i]]++;
		}

		vector<int> pre_sum(c + 1, 0);

		for (int i = 1; i <= c; i++) {
			pre_sum[i] = (pre_sum[i - 1] + cnt[i]);
		}

		// Let (x/y=r)

		bool f = true;

		for (int y = 1; y <= c; y++) {

			if (cnt[y] == 0) {
				continue;
			}

			for (int r = y; r <= c; r += y) {

				int left = r;

				int right = min({(left + y - 1), c});

				if ((pre_sum[right] - pre_sum[left - 1]) > 0 && (cnt[r / y] == 0)) { // It indicates that both 'r' and 'y' are present but its corresponding 'x' is not present.
					f = false;
					break;
				}
			}
		}

		if (f) {
			Yes;
		} else {
			No;
		}
	}

	return 0;
}