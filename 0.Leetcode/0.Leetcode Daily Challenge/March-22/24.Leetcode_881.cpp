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

// TLE:- WHY???

class Solution {
public:
	int numRescueBoats(vector<int>& people, int limit) {

		int n = people.size();

		multiset<int> s;

		for (int i = 0; i < n; i++) {
			s.insert(people[i]);
		}

		int cnt = 0;

		for (int i = 0; i < n; i++) {

			if (s.count(people[i])) {

				s.erase(s.find(people[i]));

				int x = limit - people[i];

				if (x == 0) {
					cnt++;
					continue;
				}

				auto itr = s.upper_bound(x);

				if (itr == s.begin()) {
					cnt++;
					continue;
				}

				itr--;

				cnt++;

				s.erase(itr);

			}
		}

		return cnt;
	}
};

class Solution {
public:
	int numRescueBoats(vector<int>& people, int limit) {

		int n = people.size();
		sort(all(people));

		int st = 0, end = (n - 1);

		int cnt = 0;

		while (st <= end) {
			if (st == end) {
				cnt++;
				break;
			}

			if (people[st] + people[end] <= limit) {
				cnt++;
				st++, end--;
			} else {
				cnt++;
				end--;
			}
		}

		return cnt;
	}
};