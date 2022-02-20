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
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {

		multiset<pair<int, int>> s;

		int n = arr.size();

		for (int i = 0; i < n; i++) {
			int d = abs(x - arr[i]);

			s.insert({d, arr[i]});
		}

		vector<int> ans;

		for (auto ele : s) {
			if (k == 0) {
				break;
			}

			ans.pb(ele.ss);
			k -= 1;
		}

		sort(all(ans));

		return ans;
	}
};