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

class Encrypter {
public:

	map<char, string> m;

	map<string, int> m1;

	Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {

		int n = keys.size();
		for (int i = 0; i < n; i++) {
			m[keys[i]] = values[i];
		}

		for (auto word : dictionary) {
			m1[encrypt(word)]++;
		}
	}

	string encrypt(string word1) {
		string temp = "";

		for (auto ch : word1) {
			temp += m[ch];
		}

		return temp;
	}

	int decrypt(string word2) {

		return m1[word2];
	}
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */