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
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {

		for (int i = 0; i < flowerbed.size();) {
			if (flowerbed[i] == 1) {
				i += 2;
			} else {

				if ((i + 1 < flowerbed.size()) and flowerbed[i + 1] == 1) {
					i += 1;
				} else if ((i - 1 >= 0) and flowerbed[i - 1] == 1) {
					i += 1;
				} else {
					n -= 1;
					i += 2;
				}
			}
		}

		return (n <= 0);
	}
};