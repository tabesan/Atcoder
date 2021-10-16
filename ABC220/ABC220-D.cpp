#include "bits/stdc++.h"
using namespace std;

const long long md = 998244353;
int main(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(10));
    dp[2][(a[1] + a[2]) % 10] += 1;
    dp[2][(a[1] * a[2]) % 10] += 1;
    for(int i = 3;i <= n;i++){
        for(int j = 0;j <= 9;j++){
            if (dp[i - 1][j]) {
                dp[i][(j + a[i]) % 10] += dp[i - 1][j];
                dp[i][(j + a[i]) % 10] %= md;
                dp[i][(j * a[i]) % 10] += dp[i - 1][j];
                dp[i][(j * a[i]) % 10] %= md;
            }
        }
    }

    for(int i = 0;i <= 9;i++){
        cout << (dp[n][i] + md) % md << endl;
    }
}