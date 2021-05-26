#include "bits/stdc++.h"
using namespace std;

const long long MOD = 1e9 + 7;
int main(){
    int n, l;
    cin >> n >> l;
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1;i <= n;i++){
        if (i - 1 >= 0){
            dp[i] += dp[i - 1];
            dp[i] %= MOD;
        }
        if (i - l >= 0){
            dp[i] += dp[i - l];
            dp[i] %= MOD;
        }
    }

    cout << dp[n] << endl;
}