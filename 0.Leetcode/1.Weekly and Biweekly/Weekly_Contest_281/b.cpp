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

class Solution {
public:
	ListNode* mergeNodes(ListNode* head) {

		ListNode* h1 = nullptr, *p1 = nullptr;

		ListNode*temp = head->next;

		int sm = 0;

		while (temp != nullptr) {

			if (temp->val == 0) {
				ListNode* n = new ListNode(sm);
				sm = 0;

				if (h1 == nullptr) {
					h1 = n;
					p1 = n;
				} else {
					p1->next = n;
					p1 = p1->next;
				}
			} else {
				sm += (temp->val);
			}

			temp = temp->next;
		}

		return h1;
	}
};