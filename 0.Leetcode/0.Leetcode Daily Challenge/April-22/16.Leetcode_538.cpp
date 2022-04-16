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

	int total_sm(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}

		return (root->val) + total_sm(root->left) + total_sm(root->right);
	}

	void dfs(TreeNode* root, int total, int &sm) {
		if (root == nullptr) {
			return;
		}

		dfs(root->left, total, sm);
		int x = (total - sm);
		sm += root->val;
		root->val = x;

		dfs(root->right, total, sm);
	}

	TreeNode* convertBST(TreeNode* root) {
		if (root == nullptr) {
			return root;
		}

		if (root->left == nullptr && root->right == nullptr) {
			return root;
		}

		int sum = total_sm(root);

		int sm = 0;

		dfs(root, sum, sm);

		return root;
	}
};