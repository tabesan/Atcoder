#include "bits/stdc++.h"
using namespace std;

int c[1010];
int dfs(int pos, int par, int goal, vector<vector<pair<int, int>>> &g) {
    if (pos == goal) {
        return 1;
    }

    for(auto v : g[pos]) {
        if (v.first != par) {
            if (dfs(v.first, pos, goal, g)) {
                c[v.second]++;
                return 1;
            }
        }
    }

    return 0;
}

long long dp[2][201010];
const long long M = 998244353;
int main(){
    const int base = 100005;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    for(int i = 0;i < m;i++){
        cin >> a[i];
        a[i]--;
    }

    vector<vector<pair<int, int>>> g(n);
    for(int i = 0;i < n - 1;i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }

    for(int i = 0;i < m - 1;i++){
        dfs(a[i], -1, a[i + 1], g);
    }
    
    dp[0][base] = 1;
    for(int i = 0;i < n - 1;i++){
        int cur = i % 2;
        int nx = 1 - cur;
        for(int j = 0;j < 201010;j++){
            dp[nx][j] = 0;
        }
        for(int j = 0;j < 201010;j++){
            if (dp[cur][j] > 0) {
                dp[nx][j - c[i]] += dp[cur][j];
                dp[nx][j - c[i]] %= M;
                dp[nx][j + c[i]] += dp[cur][j];
                dp[nx][j + c[i]] %= M;
            }
        }
    }

    cout << dp[(n - 1) % 2][k + base] << endl;
}