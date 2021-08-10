#include "bits/stdc++.h"
using namespace std;
#define mod 998244353

int main(){
    int n, m, k, u, v;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    long long dp1[5010], dp2[5010];
    for(int i = 0;i < m;i++){
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0;i < n;i++){
        dp1[i] = 0LL;
    }
    dp1[0] = 1LL;

    long long sum = 0;
    for(int i = 0;i < k;i++){
        sum = 0LL;
        for(int j = 0;j < n;j++){
            sum += dp1[j];
        }
    
        for(int j = 0;j < n;j++){
            dp2[j] = sum - dp1[j];
            int sz = g[j].size();
            for(int l = 0;l < sz;l++){
                dp2[j] -= dp1[g[j][l]];
            }
            dp2[j] %= mod;
        }
        for(int j = 0;j < n;j++){
            dp1[j] = dp2[j];
        }
    }   

    cout << dp1[0] % mod << endl;
}