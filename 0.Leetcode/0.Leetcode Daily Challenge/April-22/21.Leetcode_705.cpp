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

class MyHashSet {
public:

	unordered_set<int> s;

	MyHashSet() {
	}

	void add(int key) {
		s.insert(key);
	}

	void remove(int key) {
		if (s.count(key)) {
			s.erase(s.find(key));
		}
	}

	bool contains(int key) {
		return s.count(key);
	}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */