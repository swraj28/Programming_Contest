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
	int maxArea(vector<int>& height) {

		int n = height.size();
		int st = 0, end = (n - 1);

		int mx = 0;

		while (st < end) {
			int storage = (end - st) * min(height[st], height[end]);
			mx = max(mx, storage);

			if (height[st] == height[end]) {
				st++, end--;
			} else if (height[st] > height[end]) {
				end--;
			} else {
				st++;
			}
		}

		return mx;
	}
};