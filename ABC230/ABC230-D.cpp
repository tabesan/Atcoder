#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, d;
    cin >> n >> d;
    vector<pair<int, int>> lr(n);
    for(int i = 0;i < n;i++) {
        cin >> lr[i].first >> lr[i].second;
    }

    sort(lr.begin(), lr.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });
    
    long long ans = 0;
    long long pre = -1e9;
    for(auto v : lr) {
        if (pre + d - 1 < v.first) {
            ans++;
            pre = v.second;
        }
    }

    cout << ans << endl;
}