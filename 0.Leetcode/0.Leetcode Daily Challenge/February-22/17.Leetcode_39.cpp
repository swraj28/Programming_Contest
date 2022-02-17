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

	vector<vector<int>> ans;

	void recur(vector<int>& candidates, int n, int si, int target, vector<int> &v) {

		if (si >= n) {
			if (target == 0) {
				ans.pb(v);
			}
			return;
		}

		if (target >= candidates[si]) {

			v.pb(candidates[si]);
			recur(candidates, n, si, target - candidates[si], v);

			v.pop_back();
		}

		recur(candidates, n, si + 1, target, v);
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

		int n = candidates.size();

		vector<int> v;

		recur(candidates, n, 0, target, v);

		return ans;
	}
};