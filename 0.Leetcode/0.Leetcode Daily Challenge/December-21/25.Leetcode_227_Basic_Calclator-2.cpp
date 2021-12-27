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

// Infix Expression Evaluation

class Solution {
public:
	int calculate(string s) {

		stack<char> Operator;

		stack<int> Operand;

		int n = s.length();

		string x = "";

		for (int i = 0; i < n; i++) {
			if (s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/') {
				Operator.push(s[i]);
				if (x.length() > 0) {
					int val = stoi(x);
					Operand.push(val);
					x = "";
				}
			} else {
				x += s[i];
			}
		}

		if (x.length() > 0) {
			int val = stoi(x);
			Operand.push(val);
		}

		while (!Operator.empty()) {

			char op = Operator.top();
			Operator.pop();

			int y = Operand.top();
			Operand.pop();
			int x = Operand.top();
			Operand.pop();

			cout << x << " " << y << endl;

			int val = 0;

			if (op == '+') {
				val = x + y;
			} else if (op == '-') {
				val = x - y;
			} else if (op == '*') {
				val = x * y;
			} else {
				val = (x / y);
			}

			Operand.push(val);
		}

		return Operand.top();
	}
};