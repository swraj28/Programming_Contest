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

    ll lcm(ll a, ll b) {

        return (a * (ll)b) / (__gcd(a, b));
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {

        int n = nums.size();

        stack<ll> s;

        for (int i = 0; i < n; i++) {

            ll val = nums[i];

            if (!s.empty() && __gcd(s.top(), val) > 1) {

                while (!s.empty() && __gcd(s.top(), val) > 1) {

                    val = lcm(val, s.top());
                    s.pop();
                }

                s.push(val);
            } else {
                s.push(val);
            }
        }

        vector<int> ans;

        while (!s.empty()) {
            ans.pb((int)s.top());
            s.pop();
        }

        reverse(all(ans));

        return ans;
    }
};