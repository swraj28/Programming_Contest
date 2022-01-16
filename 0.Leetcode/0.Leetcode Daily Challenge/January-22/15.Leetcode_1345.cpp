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
	int minJumps(vector<int>& arr) {

		int n = arr.size();

		unordered_map<int, vector<int>> indicesOfValue;

		for (int i = 0; i < n; i++) {
			indicesOfValue[arr[i]].push_back(i);
		}

		vector<bool> visited(n, 0);

		visited[0] = true;

		queue<int> q;
		q.push(0);

		int step = 0;
		while (!q.empty()) {

			for (int size = q.size(); size > 0; --size) {
				int i = q.front();
				q.pop();
				if (i == n - 1) return step; // Reached to last index

				vector<int>& next = indicesOfValue[arr[i]];

				next.push_back(i - 1); next.push_back(i + 1);

				for (int j : next) {
					if (j >= 0 && j < n && !visited[j]) {

						visited[j] = true;

						q.push(j);
					}
				}

				next.clear(); // avoid later lookup indicesOfValue arr[i]
			}

			step++;
		}

		return 0;
	}
};