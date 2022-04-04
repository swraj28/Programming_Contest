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
	vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

		vector<int> v1, v2;

		set<int> s1(all(nums1)), s2(all(nums2));

		set_difference(all(s1), all(s2), back_inserter(v1));
		set_difference(all(s2), all(s1), back_inserter(v2));

		return {v1, v2};
	}
};