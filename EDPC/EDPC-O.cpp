#include "bits/stdc++.h"
using namespace std;
const long long MOD = 1e9 + 7;

long long dp[30][1 << 21];
int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> a[i][j];
        }
    }

    dp[0][0] = 1;
    for(int i = 0;i < n;i++){
        for(int bit = 0;bit < (1 << n);bit++){
            if (i != __builtin_popcount(bit)) continue;
            for(int j = 0;j < n;j++){
                if (!(bit & (1 << j))) {
                    if (a[i][j]) {
                        dp[i + 1][bit | (1 << j)] += dp[i][bit];
                        dp[i + 1][bit | (1 << j)] %= MOD;
                    }
                }
            }
        }
    }

    cout << dp[n][(1 << n) - 1] << endl;
}