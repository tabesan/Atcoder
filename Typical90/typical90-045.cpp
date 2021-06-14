#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n);
    for(int i = 0;i < n;i++){
        cin >> x[i] >>  y[i];
    }
    vector<vector<long long>> mx(n, vector<long long>(n));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            mx[i][j] = (long long)(x[i] - x[j])*(x[i] - x[j]) + (long long)(y[i] - y[j])*(y[i] - y[j]);
        }
    }

    vector<long long> cost(1 << n);
    for(int bit = 1;bit < (1 << n);bit++){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++){
                if (((bit >> i) & 1) == 1 && ((bit >> j) & 1) == 1) {
                    cost[bit] = max(cost[bit], mx[i][j]);
                }
            }
        }
    }
    
    vector<vector<long long>> dp(k + 1, vector<long long>(1 << n, 1LL << 62));
    dp[0][0] = 0;
    for(int i = 1;i <= k;i++){
        for(int bit = 1;bit < (1 << n);bit++){
            for(int j = bit; j != 0; j = (j - 1) & (bit)){
                dp[i][bit] = min(dp[i][bit], max(dp[i - 1][bit - j], cost[j]));
            }
        }
    }

    cout << dp[k][(1 << n) - 1] << endl;
    return 0;
}