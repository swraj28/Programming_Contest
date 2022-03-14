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
	TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

		unordered_map<int, pair<TreeNode*, TreeNode*>> m;

		int n = descriptions.size();

		for (int i = 0; i < n; i++) {

			int node = descriptions[i][0], child = descriptions[i][1], is_left = descriptions[i][2];

			if (m.find(node) != m.end()) {

				if (m.find(child) != m.end()) {
					if (is_left) {
						m[node].ff->left = m[child].ff;
					} else {
						m[node].ff->right = m[child].ff;
					}
					m[child].ss = m[node].ff;
				} else {

					TreeNode* n = new TreeNode(child);

					m[child] = {n, nullptr};

					if (is_left) {
						m[node].ff->left = m[child].ff;
					} else {
						m[node].ff->right = m[child].ff;
					}

					m[child].ss = m[node].ff;
				}
			} else {
				TreeNode* n1 = new TreeNode(node);

				m[node] = {n1, nullptr};

				if (m.find(child) != m.end()) {
					if (is_left) {
						m[node].ff->left = m[child].ff;
					} else {
						m[node].ff->right = m[child].ff;
					}
					m[child].ss = m[node].ff;
				} else {

					TreeNode* n = new TreeNode(child);

					m[child] = {n, nullptr};

					if (is_left) {
						m[node].ff->left = m[child].ff;
					} else {
						m[node].ff->right = m[child].ff;
					}

					m[child].ss = m[node].ff;
				}
			}
		}

		TreeNode* root = nullptr;

		for (auto ele : m) {
			if (ele.ss.ss == nullptr) {
				root = ele.ss.ff;
				break;
			}
		}

		return root;
	}
};