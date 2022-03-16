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
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

		int n = pushed.size();

		int idx = 0;

		vector<int> stack;
		int sze = 0;

		for (int i = 0; i < n; i++) {

			while (sze > 0 && stack[sze - 1] == popped[idx]) {
				stack.pop_back();
				sze -= 1;
				idx++;
			}

			stack.pb(pushed[i]);
			sze++;
		}

		// cout << idx << " " << sze << endl;

		while (idx < n) {
			if (sze > 0) {
				if (stack[sze - 1] == popped[idx]) {
					stack.pop_back();
					sze -= 1;
					idx++;
				} else {
					return false;
				}
			} else {
				return false;
			}
		}

		return true;
	}
};