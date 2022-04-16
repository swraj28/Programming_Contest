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

	TreeNode* dfs(TreeNode* root, int low, int high) {
		if (root == nullptr) {
			return nullptr;
		}

		if (root->val < low) {
			return dfs(root->right, low, high);
		} else if (root->val > high) {
			return dfs(root->left, low, high);
		}

		root->left = dfs(root->left, low, high);
		root->right = dfs(root->right, low, high);

		return root;
	}

	TreeNode* trimBST(TreeNode* root, int low, int high) {

		TreeNode* ans = dfs(root, low, high);

		return ans;
	}
};