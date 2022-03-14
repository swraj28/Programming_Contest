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
	ListNode* rotateRight(ListNode* head, int k) {

		if (head == nullptr) {
			return head;
		}

		if (k == 0) {
			return head;
		}

		int len = 0;

		ListNode* temp = head;

		while (temp != nullptr) {
			len++;
			temp = temp->next;
		}

		if (k % len == 0) {
			return head;
		}

		k %= len;

		k -= 1;

		// Now the Question Boils Down to Delete the nth node from last. (We will solve it in Single Pass From Here).

		ListNode* fast = head;

		while (k--) {
			fast = fast->next;
		}

		ListNode* slow = head, *prev = nullptr;

		while ((fast->next) != nullptr) {
			prev = slow;
			slow = slow->next;
			fast = fast->next;
		}

		prev->next = nullptr;

		fast->next = head;
		head = slow;

		return head;
	}
};