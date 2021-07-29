#include "bits/stdc++.h"
using namespace std;
const long long MOD = 1e9 + 7;

vector<int> g[100010];
long long dp[100010][2];

void dfs(int pos, int par){
    dp[pos][0] = 1;
    dp[pos][1] = 1;
    for(auto v : g[pos]) {
        if (v == par) continue;
        dfs(v, pos);
        dp[pos][0] = dp[pos][0]*((dp[v][0] + dp[v][1])%MOD);
        dp[pos][0] %= MOD;
        dp[pos][1] = dp[pos][1]*(dp[v][0] % MOD);
        dp[pos][1] %= MOD;
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n - 1;i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1);

    long long ans = (dp[0][0] + dp[0][1]) % MOD;
    cout << ans << endl;
}