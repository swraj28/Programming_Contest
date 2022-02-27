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


// 171. Excel Sheet Column Number

class Solution {
public:
	int titleToNumber(string columnTitle) {

		int ans = 0;

		int n = columnTitle.length(), len = 0;

		for (int i = n - 1; i >= 0; i--) {

			int x = (columnTitle[i] - 'A') + 1;

			ans += (x * pow(26, len));

			len++;
		}

		return ans;
	}
};

//168. Excel Sheet Column Title

class Solution {
public:
	string convertToTitle(int columnNumber) {

		string ans = "";

		while (columnNumber) {

			int x = ((columnNumber - 1) % 26);

			char ch = 'A' + x;

			ans += ch;

			columnNumber -= 1;

			columnNumber /= 26;
		}

		reverse(all(ans));

		return ans;
	}
};