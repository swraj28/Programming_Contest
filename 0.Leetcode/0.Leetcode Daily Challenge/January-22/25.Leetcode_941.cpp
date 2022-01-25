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
	bool validMountainArray(vector<int>& arr) {

		int n = arr.size();

		if (n < 3) {
			return false;
		}

		bool inc = false, dec = false;

		for (int i = 1; i < n; i++) {
			if (arr[i] == arr[i - 1]) {
				return false;
			}

			if ((arr[i] > arr[i - 1])) {
				if (dec == true) {
					return false;
				}

				if (inc == false) {
					inc = true;
				}
			}

			if (arr[i] < arr[i - 1]) {
				if (inc == false) {
					return false;
				}

				if (dec == false) {
					dec = true;
				}
			}
		}

		return (inc & dec);
	}
};