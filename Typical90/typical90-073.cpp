#include "bits/stdc++.h"
using namespace std;
const long long MOD = 1e9 + 7;

char c[1000000];
long long dp[1000000][3];
void dfs(int pos, int par, vector<vector<int>> &g) {
    long long v1 = 1, v2 = 1;
    for(auto nx : g[pos]){
        if (nx == par) continue;
        dfs(nx, pos, g);
        if (c[pos] == 'a'){
            v1 *= dp[nx][0] + dp[nx][2];
            v2 *= dp[nx][0] + dp[nx][1] + 2LL*dp[nx][2];
        } else {
            v1 *= dp[nx][1] + dp[nx][2];
            v2 *= dp[nx][0] + dp[nx][1] + 2LL*dp[nx][2];
        }
        v1 %= MOD;
        v2 %= MOD;
    }

    if (c[pos] == 'a') {
        dp[pos][0] = v1;
        dp[pos][2] = (v2 - v1 + MOD) % MOD;
    } else {
        dp[pos][1] = v1;
        dp[pos][2] = (v2 - v1 + MOD) % MOD;
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> c[i];
    }

    vector<vector<int>> g(n + 1);
    for(int i = 1;i <= n - 1;i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, -1, g);
    cout << dp[1][2] << endl;
}