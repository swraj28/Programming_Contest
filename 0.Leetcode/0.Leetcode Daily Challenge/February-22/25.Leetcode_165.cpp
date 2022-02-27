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
	int compareVersion(string version1, string version2) {

		int n = version1.size(), m = version2.size();

		vector<int> v1, v2;

		string x = "";

		for (int i = 0; i < n; i++) {
			if (version1[i] == '.') {
				v1.pb(stoi(x));
				x = "";
			} else {
				x += version1[i];
			}
		}

		v1.pb(stoi(x));

		x = "";

		for (int i = 0; i < m; i++) {
			if (version2[i] == '.') {
				v2.pb(stoi(x));
				x = "";
			} else {
				x += version2[i];
			}
		}

		v2.pb(stoi(x));

		n = v1.size(), m = v2.size();

		int i = 0, j = 0;

		while (i < n && j < m) {

			if (v1[i] == v2[j]) {
				i++, j++;
			} else if (v1[i] > v2[i]) {
				return 1;
			} else {
				return -1;
			}
		}

		while (i < n) {
			if (v1[i] > 0) {
				return 1;
			}

			i++;
		}

		while (j < m) {
			if (v2[j] > 0) {
				return -1;
			}
			j++;
		}

		return 0;
	}
};