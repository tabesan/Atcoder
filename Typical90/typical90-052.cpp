#include "bits/stdc++.h"
using namespace std;

const long long MOD = 1e9 + 7;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(6));
    vector<vector<long long>> dp(n, vector<long long>(6, 0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 6;j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0;i < 6;i++){
        dp[0][i] = a[0][i];
    }
    for(int i = 1;i < n;i++){
        for(int j = 0;j < 6;j++){
            for(int k = 0;k < 6;k++){
                dp[i][j] += a[i][j]*dp[i - 1][k];
                dp[i][j] %= MOD;
            }
        }
    }

    long long sum = 0;
    for(int i = 0;i < 6;i++){
        sum += dp[n - 1][i];
        sum %= MOD;
    }
    cout << sum << endl;
}