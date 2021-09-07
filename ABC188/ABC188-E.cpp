#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    vector<vector<int>> g(n);
    for(int i = 0;i < m;i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
    }

    long long ans = -1e9;
    vector<long long> dp(n, -1e9);
    for(int i = n - 1;i >= 0;i--){
        for(auto nx : g[i]){
            dp[i] = max(dp[i], dp[nx]);
        }
        ans = max(ans, dp[i] - a[i]);
        dp[i] = max(dp[i], a[i]);
    }

    cout << ans << endl;
}