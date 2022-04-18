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

	void dfs(TreeNode* root, int &k, int &ans) {
		if (root == nullptr) {
			return;
		}

		dfs(root->left, k, ans);
		k -= 1;
		if (k == 0) {
			ans = root->val;
			return;
		}
		dfs(root->right, k, ans);
	}

	int kthSmallest(TreeNode* root, int k) {

		int ans = -1;
		dfs(root, k, ans);

		return ans;
	}
};