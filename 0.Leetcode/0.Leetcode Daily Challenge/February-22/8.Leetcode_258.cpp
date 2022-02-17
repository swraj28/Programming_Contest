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

// Brute Force:-

class Solution {
public:
	int addDigits(int num) {

		if (num <= 9) {
			return num;
		}

		string s = to_string(num);

		while (true) {

			if (s.length() == 1) {
				break;
			}

			int x = 0;

			for (auto ch : s) {
				x += (ch - '0');
			}

			s = to_string(x);
		}

		num = stoi(s);

		return num;
	}
};

// o(1) Approach:-

/*
        The O(1) approach says :

		Check if the number is 0 or not . If num==0 , return 0. Else do the following.
		Check if (num%9)==0 . If it is true , return 9. Else return (num%9).

		The logic behind this approach , I think is related to the divisibility test of 9.

		The O(1) approach method is called Digit Root.
*/

class Solution {
public:
	int addDigits(int num) {
		if (num == 0)
			return 0;
		else if (num % 9 == 0)
			return 9;
		else
			return num % 9;
	}
};