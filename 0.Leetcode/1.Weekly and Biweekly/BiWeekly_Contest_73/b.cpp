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
	vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

		map<int, vector<int>> m;

		for (auto num : nums) {

			if (num == 0) {
				m[mapping[num]].pb(num);
				continue;
			}

			int val = 0;
			int p = 1;
			int temp = num;
			while (num > 0) {

				int rem = (num % 10);
				rem = mapping[rem];
				rem *= p;
				val += rem;
				p *= 10;

				num /= 10;
			}

			m[val].pb(temp);
		}

		vector<int> ans;

		for (auto ele : m) {

			for (auto i : ele.ss) {
				ans.pb(i);
			}
		}

		return ans;
	}
};