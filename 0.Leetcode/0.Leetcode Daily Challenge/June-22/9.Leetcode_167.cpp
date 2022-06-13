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
	std::vector<int> v;
	vector<int> twoSum(vector<int>& numbers, int target) {

		int n = numbers.size();

		for (int i = 0; i < n; i++) {
			int a = numbers[i], b = target - numbers[i];

			int s = i + 1, e = n - 1;
			while (s <= e) {
				int m = s + (e - s) / 2;

				if (numbers[m] == b) {
					v.push_back(i + 1);
					v.push_back(m + 1);
					return v;
				}

				if (numbers[m] < b) {
					s = m + 1;
				} else {
					e = m - 1;
				}
			}
		}

		return v;

	}
};