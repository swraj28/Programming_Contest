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
// #define all(v) (v).begin(),(v).end()
#define ms(arr, v) memset(arr, v, sizeof(arr))

class Bitset {
public:

    vector<int> BitSet, flip_BitSet;

    int o_cnt_1 = 0, z_cnt_1 = 0;

    int o_cnt_2 = 0, z_cnt_2 = 0;

    int sze = 0;

    bool f = true; // 1--> BitSet 0--> flip_BitSet

    Bitset(int size) {
        BitSet.assign(size, 0);
        flip_BitSet.assign(size, 1);
        z_cnt_1 = size;

        o_cnt_2 = size;

        sze = size;
    }

    void fix(int idx) {
        if (f) {
            if (BitSet[idx] == 0) {
                BitSet[idx] = 1;
                flip_BitSet[idx] = 0;

                o_cnt_1++;
                z_cnt_1--;

                o_cnt_2--;
                z_cnt_2++;
            }
        } else {
            if (flip_BitSet[idx] == 0) {
                flip_BitSet[idx] = 1;
                BitSet[idx] = 0;

                o_cnt_1--;
                z_cnt_1++;

                o_cnt_2++;
                z_cnt_2--;
            }
        }
    }

    void unfix(int idx) {
        if (f) {
            if (BitSet[idx] == 1) {
                BitSet[idx] = 0;
                flip_BitSet[idx] = 1;

                o_cnt_1--;
                z_cnt_1++;

                o_cnt_2++;
                z_cnt_2--;
            }
        } else {
            if (flip_BitSet[idx] == 1) {
                flip_BitSet[idx] = 0;
                BitSet[idx] = 1;

                o_cnt_2--;
                z_cnt_2++;

                o_cnt_1++;
                z_cnt_1--;
            }
        }
    }

    void flip() {
        if (f) {
            f = false;
        } else {
            f = true;
        }
    }

    bool all() {
        if (f) {
            return (o_cnt_1 == sze) ? 1 : 0;
        }

        return (o_cnt_2 == sze) ? 1 : 0;
    }

    bool one() {
        if (f) {
            return (o_cnt_1 > 0) ? 1 : 0;
        }

        return (o_cnt_2 > 0) ? 1 : 0;
    }

    int count() {
        if (f) {
            return o_cnt_1;
        } else {
            return o_cnt_2;
        }
    }

    string toString() {
        string ans = "";

        if (f) {
            for (int i = 0; i < sze; i++) {
                ans += (BitSet[i] + '0');
            }
        } else {
            for (int i = 0; i < sze; i++) {
                ans += (flip_BitSet[i] + '0');
            }
        }

        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */