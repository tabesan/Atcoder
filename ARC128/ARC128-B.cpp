#include "bits/stdc++.h"
using namespace std;

int main(){
    int t;
    cin >> t;
    long long r, g, b;
    vector<long long> res;
    for(int i = 0;i < t;i++) {
        long long ans = 1e18 + 1;
        cin >> r >> g >> b;
        if (g % 3 == b % 3) {
            if (g >= b) {
                ans = min(ans, g);
            } else {
                ans = min(ans, b);
            }
        }

        if (g % 3 == r % 3) {
            if (g >= r) {
                ans = min(ans, g);
            } else {
                ans = min(ans, r);
            }
        }

        if (b % 3 == r % 3) {
            if (b >= r) {
                ans = min(ans, b);
            } else {
                ans = min(ans, r);
            }
        }

        res.push_back(ans);
    }

    for(auto v : res) {
        if (v == 1e18 + 1) {
            cout << -1 << endl;
        } else {
            cout << v << endl;
        }
    }
}