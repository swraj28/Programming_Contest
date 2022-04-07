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
	int lastStoneWeight(vector<int>& stones) {

		priority_queue<int> pq(all(stones));

		while ((int)pq.size() >= 2) {

			auto f1 = pq.top();
			pq.pop();
			auto f2 = pq.top();
			pq.pop();

			if (f1 == f2) {
				continue;
			}

			pq.push(abs(f1 - f2));
		}

		return ((int)pq.size() > 0) ? (int)pq.top() : 0;
	}
};