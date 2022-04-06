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

class Solution {
public:
    vector<int> maximumBobPoints(int numarrows, vector<int>& alicearrows) {

        int n(1 << 12), maxscore(0);

        vector<int> res;

        for (int mask = 1; mask < n; mask++) {

            int arrowsleft(numarrows), score(0);

            vector<int> bob(12, 0);

            // checking for all the targets

            for (int i = 0; i <= 11; i++) {
                //for checking the bit is set or not at that mask
                if (mask & (1 << i)) {

                    int arrowsneeded = alicearrows[i] + 1;
                    // If the number of arrows required to reach the current target
                    // exceeds the number of arrows available,
                    // then this combination will not result in a right answer, so we will break.
                    if (arrowsneeded > arrowsleft) {
                        score = -1;
                        break;
                    }
                    score += i;
                    // bob[i] is arrows Bob must hit to achieve this score
                    bob[i] = arrowsneeded;
                    arrowsleft -= arrowsneeded;
                }
            }

            if (score > maxscore) {
                // in case any arrows are left after hitting targets, we can add it to any target
                if (arrowsleft) bob[0] += arrowsleft;
                maxscore = score;
                res = bob;
            }
        }

        return res;
    }
};