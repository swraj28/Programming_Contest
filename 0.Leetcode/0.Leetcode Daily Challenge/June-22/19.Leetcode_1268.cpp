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
	vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {

		sort(all(products));

		int n = searchWord.length();

		string s = "";

		vector<vector<string>> ans;

		for (int i = 0; i < n; i++) {
			s += searchWord[i];

			int idx = lower_bound(all(products), s) - products.begin();

			vector<string> v;

			for (int j = 0; j < 3 && j + idx < products.size(); j++, idx++) {
				string temp = products[idx];

				if (temp.find(s)) {
					break;
				}

				v.pb(temp);
			}

			ans.pb(v);
		}

		return ans;
	}
};