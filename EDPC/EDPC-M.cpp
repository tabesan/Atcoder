#include "bits/stdc++.h"
using namespace std;
const long long MOD = 1e9 + 7;

long long dp[110][100010];
long long sum[100010];
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }

    dp[0][0] = 1;
    for(int i = 1;i <= n;i++){
        sum[0] = 0;
        for(int j = 1;j <= k + 1;j++){
            sum[j] = (sum[j - 1] + dp[i - 1][j - 1]) % MOD;
        }

        for(int j = 0;j <= k;j++){
            dp[i][j] = (sum[j + 1] - sum[max(0, j - a[i])] + MOD) % MOD;
        }
    }

    cout << dp[n][k] << endl;
}