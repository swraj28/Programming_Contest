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
	vector<int> sequentialDigits(int low, int high) {

		vector<int> v;

		for (int i = 1; i <= 9; i++) {
			string s = "";
			s += (i + '0');
			for (int j = i + 1; j <= 9; j++) {
				s += (j + '0');

				int x = stoi(s);

				v.pb(x);
			}
		}

		vector<int> ans;

		for (auto ele : v) {
			if (ele >= low and ele <= high) {
				ans.pb(ele);
			}
		}

		sort(all(ans));

		return ans;
	}
};