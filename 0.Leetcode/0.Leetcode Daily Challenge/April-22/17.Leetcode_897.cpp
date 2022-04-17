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

	TreeNode* res = nullptr, *prev = nullptr;

	void dfs(TreeNode* root) {
		if (root == nullptr) {
			return;
		}

		dfs(root->left);
		if (res == nullptr) {
			res = root;
		} else {
			prev->right = root;
		}

		prev = root;

		root->left = nullptr;  // Dry run on a BST to understand this

		dfs(root->right);
	}

	TreeNode* increasingBST(TreeNode* root) {

		dfs(root);

		return res;
	}
};