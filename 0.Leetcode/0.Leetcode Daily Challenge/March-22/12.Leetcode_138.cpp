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

// Definition for a Node.

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// 1.soln: - Using Extra space

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == nullptr) {
            return nullptr;
        }

        map<Node*, Node*> m;

        Node* ptr = head;

        while (ptr != nullptr) {
            m[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }

        ptr = head;

        while (ptr != nullptr) {
            m[ptr]->next = m[(ptr->next)];
            m[ptr]->random = m[(ptr->random)];
            ptr = ptr->next;
        }

        return m[head];
    }
};

// 2. Without Extra Space:-

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == nullptr) {
            return head;
        }

        Node* curr = head;

        while (curr != nullptr) {
            Node* forward = curr->next;
            Node* n = new Node(curr->val);
            curr->next = n;
            n->next = forward;

            curr = forward;
        }

        curr = head;

        while (curr != nullptr) {
            if ((curr->random) != nullptr) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        Node* prev = new Node(-1);
        Node* h1 = prev;
        curr = head;

        while (curr != nullptr) {
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev = prev->next;
            curr = curr->next;
        }

        h1 = h1->next;

        return h1;
    }
};