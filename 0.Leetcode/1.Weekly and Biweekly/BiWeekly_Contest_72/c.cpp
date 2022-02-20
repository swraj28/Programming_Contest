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
	vector<long long> maximumEvenSplit(long long finalSum) {

		if (finalSum % 2) {
			return {};
		}

		vector<ll> v;

		unordered_set<ll> s;

		ll st = 2;

		while (true) {

			if (finalSum == 0) {
				break;
			}

			finalSum -= st;
			s.insert(st);

			if (s.find(finalSum) != s.end()) {
				finalSum += st;

				v.pb(finalSum);
				finalSum = 0;
			} else {

				v.pb(st);
			}

			st += 2;
		}

		return v;
	}
};