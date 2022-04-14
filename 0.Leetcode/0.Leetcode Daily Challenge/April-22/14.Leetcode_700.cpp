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

//Definition for a binary tree node.

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == NULL) {
			return NULL;
		}

		if (root->val == val) {
			return root;
		}

		TreeNode* n1 = NULL;
		TreeNode* n2 = NULL;

		if (val > root->val) {
			n1 = searchBST(root->right, val);
		} else {
			n2 = searchBST(root->left, val);
		}

		if (n1 != NULL) {
			return n1;
		} else if (n2 != NULL) {
			return n2;
		}

		return NULL;
	}
};