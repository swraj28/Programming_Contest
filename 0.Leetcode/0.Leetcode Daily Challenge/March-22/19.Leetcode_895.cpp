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

class FreqStack {
public:
	FreqStack() {

	}

	set<vector<int>> s;

	unordered_map<int, int> m;

	int timestamp = 0;

	void push(int val) {
		m[val]++;

		s.insert({m[val], timestamp, val});

		timestamp++;
	}

	int pop() {

		auto itr = s.end();
		itr--;

		auto v = (*itr);

		s.erase(itr);

		m[v[2]] -= 1;

		return v[2];
	}
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */