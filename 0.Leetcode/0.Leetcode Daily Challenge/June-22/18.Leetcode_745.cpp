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

class node {
public:
	char ch;
	unordered_map<char, node*> h;
	bool isTerminal;

	int idx;

	node(char ch) {
		this->ch = ch;
		this->isTerminal = false;

		this->idx = -1;
	}
};

class WordFilter {
public:

	node* root = new node('\0');

	void insert(string word, int idx) {

		node* temp = root;

		for (int i = 0; i < word.length(); i++) {

			char ch = word[i];

			if (temp->h.count(ch)) {
				temp->h[ch]->idx = idx;
				temp = temp->h[ch];
			} else {
				node* child = new node(ch);
				child->idx = idx;
				temp->h[ch] = child;
				temp = temp->h[ch];
			}
		}

		temp->isTerminal = true;
	}

	WordFilter(vector<string>& words) {

		for (int i = 0; i < words.size(); i++) {

			string s = words[i];
			string temp = "#";
			temp += s;

			for (int j = s.size() - 1; j >= 0; j--) {
				temp = s[j] + temp;

				// cout<<temp<<endl;

				insert(temp, i);
			}
		}
	}

	int f(string prefix, string suffix) {

		string s = suffix + "#" + prefix;

		node*temp = root;

		int ans = -1;

		for (auto &ch : s) {
			if (temp->h.count(ch) == 0) {
				return -1;
			} else {
				ans = temp->h[ch]->idx;
				temp = temp->h[ch];
			}
		}

		return ans;
	}
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */