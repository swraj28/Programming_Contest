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

// Definition for singly-linked list.

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1. Brute Force:-

class Solution {
public:

	vector<int> v;
	Solution(ListNode* head) {

		ListNode* temp = head;
		while (temp != nullptr) {
			v.pb(temp->val);
			temp = temp->next;
		}
	}

	int getRandom() {
		return v[rand() % v.size()];
	}
};

// 2. Optimized:-

/*
    What if the linked list is extremely large and its length is unknown to you?
    Could you solve this efficiently without using extra space?

    It can be solve using the concepts of Reservoir Sampling:-
*/

class Solution {
public:

	Solution(ListNode* head) {
	}

	int getRandom() {

	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */