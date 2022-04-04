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
	int convertTime(string current, string correct) {

		int h1 = stoi(current.substr(0, 2));
		int h2 = stoi(correct.substr(0, 2));
		int m1 = stoi(current.substr(3));
		int m2 = stoi(correct.substr(3));

		int total = (h2 - h1);

		int d = 0;

		if (m2 < m1) {
			total -= 1;
			d = m2;
			d += (60 - m1);
		} else {
			d = (m2 - m1);
		}

		while (d >= 15) {
			d -= 15;
			total += 1;
		}

		while (d >= 5) {
			d -= 5;
			total += 1;
		}

		while (d >= 1) {
			d -= 1;
			total++;
		}

		return total;
	}
};