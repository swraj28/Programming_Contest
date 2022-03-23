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
	vector<int> partitionLabels(string s) {

		int n = s.length();
		vector<int> mx_pos(26, 0);

		for (int i = 0; i < n; i++) {
			mx_pos[s[i] - 'a'] = max(mx_pos[s[i] - 'a'], i);
		}

		vector<int> ans;

		int l = -1, r = -1;

		for (int i = 0; i < n; i++) {
			if (l == -1 && r == -1) {
				l = i, r = mx_pos[s[i] - 'a'];
			} else {
				if (i > r) {
					ans.pb((r - l) + 1);

					l = i, r = r = mx_pos[s[i] - 'a'];
				} else {
					r = max(mx_pos[s[i] - 'a'], r);
				}
			}
		}

		if (l != -1 && r != -1) {
			ans.pb((r - l) + 1);
		}

		return ans;
	}
};