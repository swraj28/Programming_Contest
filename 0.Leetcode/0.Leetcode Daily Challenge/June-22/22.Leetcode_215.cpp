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

// Appraoch 1:- Using Inbuilt Sorting Algorithm

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size();

        sort(all(nums), greater<int>());

        return nums[k - 1];
    }
};


// Approach-2:- using min heap

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size();

        // Creates a min heap
        priority_queue <int, vector<int>, greater<int> > pq;

        for (int i = 0; i < n; i++) {
            pq.push(nums[i]);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};

// Appraoch 3:- Quick Select Algorithm
class Solution {

    int partition(vector<int> &nums, int low, int high) {

        int pivot_pos = rand() % (high - low + 1) + low; // random select pivot position(ensure the selected index between low and high index)

        int pivot = nums[pivot_pos];

        swap(nums[pivot_pos], nums[high]);

        //----below is classical quick sort process----

        int l = low - 1;

        for (int i = low; i < high; i++) {
            if (nums[i] < pivot) {
                l++;
                swap(nums[l], nums[i]);
            }
        }

        swap(nums[l + 1], nums[high]);
        return l + 1;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {

        int low = 0;
        int high = nums.size() - 1;

        int rank = nums.size() - k; //turn problem to find rank-th smallest

        while (true) {

            int pivot_pos = partition(nums, low, high);

            if (pivot_pos == rank) {
                return nums[pivot_pos];
            }

            if (pivot_pos < rank) { // if pivot_pos smaller than the rank, update low bound
                low = pivot_pos + 1;
            } else {
                high = pivot_pos - 1;
            }
        }
    }
};