#include "bits/stdc++.h"
using namespace std;

long long dp[100010][3];
int main(){
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    dp[0][0] = 0;

    for(int i = 1;i <= n;i++){
        for(int j = 0;j < 3;j++){
            if (j == 0){
                dp[i][j] = max(dp[i][j], dp[i - 1][1] + a[i]);
                dp[i][j] = max(dp[i][j], dp[i - 1][2] + a[i]);
            } else if (j == 1){
                dp[i][j] = max(dp[i][j], dp[i - 1][0] + b[i]);
                dp[i][j] = max(dp[i][j], dp[i - 1][2] + b[i]);
            } else {
                dp[i][j] = max(dp[i][j], dp[i - 1][0] + c[i]);
                dp[i][j] = max(dp[i][j], dp[i - 1][1] + c[i]);
            }
        }
    }

    long long ans = 0;
    for(int i = 0;i < 3;i++){
        ans = max(ans, dp[n][i]);
    }

    cout << ans << endl;
}