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


// 1. Simulation:-

class Solution {
public:
	bool isRobotBounded(string instructions) {

		int n = instructions.length();

		set < pair<char, pair<int, int>>> s;

		int x = 0, y = 0;

		char d = 'n';

		for (int cnt = 0; cnt < 1000; cnt++) {

			for (int i = 0; i < n; i++) {
				if (instructions[i] == 'G') {
					if (d == 'n') {
						y += 1;
					} else if (d == 's') {
						y -= 1;
					} else if (d == 'e') {
						x += 1;
					} else if (d == 'w') {
						x -= 1;
					}
				} else if (instructions[i] == 'L') {
					if (d == 'n') {
						d = 'w';
					} else if (d == 's') {
						d = 'e';
					} else if (d == 'e') {
						d = 'n';
					} else if (d == 'w') {
						d = 's';
					}
				} else if (instructions[i] == 'R') {
					if (d == 'n') {
						d = 'e';
					} else if (d == 's') {
						d = 'w';
					} else if (d == 'e') {
						d = 's';
					} else if (d == 'w') {
						d = 'n';
					}
				}
			}

			s.insert({d, {x, y}});
		}

		if (s.size() == 1000) {
			return false;
		}

		return true;
	}
};