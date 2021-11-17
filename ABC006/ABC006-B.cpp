#include "bits/stdc++.h"
using namespace std;

long long dp[1000010];
int main(){
    int n;
    cin >> n;

    dp[1] = 0, dp[2] = 0, dp[3] = 1;
    for(int i = 4;i <= n;i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        dp[i] %= 10007;
    }

    cout << dp[n] << endl;

}