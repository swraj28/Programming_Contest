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

class ATM {
public:

    map<ll, ll> m;
    vector<ll> v;

    ATM() {
        v.pb(20);
        v.pb(50);
        v.pb(100);
        v.pb(200);
        v.pb(500);
    }

    void deposit(vector<int> banknotesCount) {

        for (ll i = 0; i < banknotesCount.size(); i++) {
            m[v[i]] += (ll) banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> ans(5, 0);

        for (int i = 4; i >= 0; i--) {
            if (v[i] > amount) {
                continue;
            }

            ll x = (amount / v[i]);
            x = min(x, m[v[i]]);

            amount -= (x * v[i]);

            ans[i] += (int)x;

            m[v[i]] -= (int)x;
        }

        if (amount == 0) {
            return ans;
        }

        for (int i = 0; i < 5; i++) {
            m[v[i]] += (ans[i]);
        }

        return { -1};
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */