#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()
#define ms(arr, v) memset(arr, v, sizeof(arr))

class Solution {
public:
	string addBinary(string a, string b) {

		int carry = 0;

		reverse(all(a));
		reverse(all(b));

		int n = a.length(), m = b.length();
		int i = 0, j = 0;

		string ans = "";

		while (i < n and j < m) {
			int sm = (a[i] - '0') + (b[j] - '0') + carry;

			ans += (sm % 2) + '0';
			carry = (sm / 2);
			i++, j++;
		}

		while (i < n) {
			int sm = (a[i] - '0')  + carry;

			ans += (sm % 2) + '0';
			carry = (sm / 2);
			i++;
		}

		while (j < m) {
			int sm = (b[j] - '0') + carry;

			ans += (sm % 2) + '0';
			carry = (sm / 2);
			j++;
		}

		if (carry) {
			ans += '1';
		}

		reverse(all(ans));

		return ans;
	}
};