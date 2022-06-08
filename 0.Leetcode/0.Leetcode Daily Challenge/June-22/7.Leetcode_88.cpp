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

// 1. Using Extra Space:-

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

		vector<int> ans;

		int i = 0, j = 0;

		while (i < m && j < n) {
			if (nums1[i] <= nums2[j]) {
				ans.pb(nums1[i]);
				i++;
			} else {
				ans.pb(nums2[j]);
				j++;
			}
		}

		while (i < n) {
			ans.pb(nums1[i]);
			i++;
		}

		while (j < m) {
			ans.pb(nums2[j]);
			j++;
		}

		nums1.clear();
		nums1 = ans;
	}
};

// 2. In O(1) Extra Space:-
// Use Insertion Sort Type Technique:- O(m*n)

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

		for (int i = 0; i < m; i++) {

			if (nums1[i] > nums2[0]) {
				swap(nums1[i], nums2[0]);
			}

			// Insertion Sort
			// Right part of the second array is sorted only we need to place the first element of the second array to its correct position.

			int first = nums2[0];

			int k = 1;

			for (; k < m && nums2[k] < first; k++) {
				nums2[k - 1] = nums2[k];
			}

			nums2[k - 1] = first;
		}
	}
};

// 3. O(1) Extra Space:-
// Using Gap methode (Shell Sort )--> O((n+m)*log(n+m))

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

		int gap = ceil((double)(n + m) / 2);

		while (gap > 0) {

			int i = 0, j = gap;

			while (j < (n + m)) {
				if (j < m && nums1[i] > nums1[j]) {
					swap(nums1[i], nums1[j]);
				} else if (j >= m && i < m && nums1[i] > nums2[j - m]) {
					swap(nums1[i], nums2[j - m]);
				} else if (j >= m && i >= m && nums1[i - m] > nums2[j - m]) {
					swap(nums1[i - m], nums2[j - m]);
				}

				i++, j++;
			}

			if (gap == 1) {
				gap = 0;
			} else {
				gap = ceil((double)gap / 2);
			}
		}
	}
};