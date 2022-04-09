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

class KthLargest {
public:

	// Creates a min heap
	priority_queue <int, vector<int>, greater<int> > pq;

	int k1 = 0;

	KthLargest(int k, vector<int>& nums) {
		k1 = k;

		int n = nums.size();

		for (int i = 0; i < n; i++) {
			pq.push(nums[i]);

			if ((int)pq.size() > k) {
				pq.pop();
			}
		}
	}

	int add(int val) {
		pq.push(val);

		if ((int)pq.size() > k1) {
			pq.pop();
		}

		return (int)pq.top();
	}
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */