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

// 1. Naive Approach:-

class Solution {
public:

	vector<int> v;

	void dfs(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		v.push_back(root->val);
		dfs(root->left);
		dfs(root->right);
	}

	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

		dfs(root1);
		dfs(root2);

		sort(v.begin(), v.end());

		return v;
	}
};