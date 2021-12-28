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

	ll t;
	cin >> t;
	while (t--) {

		ll n, k;
		cin >> n >> k;

		mk(arr, n, ll);

		ll sm = 0;

		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
			sm += (ll)arr[i];
		}

		if (sm <= k) {
			cout << 0 << endl;
			continue;
		}

		if (n == 1) {
			cout << (ll)(arr[0] - k) << endl;
			continue;
		}

		if (sm == (k + 1)) {
			cout << 1 << endl;
			continue;
		}

		/*
		Key Observations:-

		            1. Operation Of Type 1 should be performed on the minimum Elements.
		            2.Operation of Type 2 should be performed from the last after sorting the array (i.e., from the maximum element)

		            3. We should perform all the operation of Type 1 before performing the Operations of Type 2.

		            Reason: Initially: Min--> X and Max-->Y
		                    1. Operation: Type1->Type2->Type1
		                                  X-1,Y
		                                  X-1,X-1
		                                  X-2,X-1

		                        Total decrement:-> X-(X-2)+ Y-(X-1)= (Y-X+3)

		                    2. Operation: Type1->Type1->Type1
		                                  X-1,Y
		                                  X-2,Y
		                                  X-2,X-2

		                        Total decrement:-> X-(X-2)+ Y-(X-2)= (Y-X+4)

		                        Therfore Operation 2 will decrease the sum more than that of Operation 1.


		            --> Toatal Decrement Required =(sm-k)=diff

		            --> If we perform some Operation of Type 1 (Let say x) and choose some suffix from the sorted array to perform Operation 2.

		            --> Let i be the last index where i performed the Type 2 Operation and x operation of Type 1 on frist element of the array.

		            --> Total decrement :- x+(a[n-1]-a[0]+x)+(a[n-2]-a[0]+x)+......+(a[i]-a[0]+x)
		                                 --> x+(a[n-1]+a[n-2]+...a[i])-(n-i)*a[0]+ (n-i)*x
		                                 --> (a[n-1]+a[n-2]+...a[i])-(n-i)*a[0]+ (n-i+1)*x

		                                 ---> total decrement:-> s_sum[i]-(n-i)*a[0]+(n-i+1)*x

		                                 --> s_sum[i]-(n-i)*a[0]+(n-i+1)*x >=diff

		                                 --> x= ceil(diff-s_sum[i]+(n-i)*a[0])/(n-i+1)
		*/

		sort(arr, arr + n);

		ll diff = (sm - k);

		vector<ll> s_sum(n, 0ll);

		ll temp = 0;

		for (ll i = n - 1; i >= 0; i--) {
			temp += (ll) arr[i];

			s_sum[i] = temp;
		}

		ll mn = (1e16);

		for (ll i = n - 1; i > 0; i--) {

			ll sum = s_sum[i];

			ll total = (n - i);

			if ((sum - (arr[0]* total)) >= diff) {
				mn = min(mn, total);
				continue;
			}

			temp = (diff - sum);

			temp += (total * (ll) arr[0]);

			ll val = ceil(temp / ((total + 1) * (1.0)));

			val += total;

			mn = min(mn, val);
		}

		cout << mn << endl;
	}

	return 0;
}