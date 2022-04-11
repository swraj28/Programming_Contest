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
	int calPoints(vector<string>& ops) {

		int n = ops.size();

		int total = 0;

		vector<int> Stack;

		int sze = 0;

		for (int i = 0; i < n; i++) {
			string s = ops[i];

			if (isdigit(s[0]) || s[0] == '-') {
				int x = stoi(s);
				Stack.pb(x);
				sze++;
			} else if (s == "C") {
				Stack.pop_back();
				sze--;
			} else if (s == "D") {
				Stack.pb(Stack[sze - 1] * 2);
				sze++;
			} else if (s == "+") {
				Stack.pb(Stack[sze - 1] + Stack[sze - 2]);
				sze++;
			}
		}

		for (auto ele : Stack) {
			total += ele;
		}

		return total;
	}
};