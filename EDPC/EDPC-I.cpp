#include "bits/stdc++.h"
using namespace std;

double dp[3010][3010];

int main(){
    int n;
    cin >> n;
    vector<double> p(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> p[i];
    }

    dp[0][0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= i;j++){
            if (j > 0){
                dp[i][j] = dp[i - 1][j]*(1 - p[i]) + dp[i - 1][j - 1]*p[i];
            } else {
                dp[i][j] = dp[i - 1][j]*(1 - p[i]);
            }
        }
    }

    double ans = 0;
    for(int i = 0;i <= n;i++){
        if (n - i < i) {
            ans += dp[n][i];
        }
    }

    cout << setprecision(12) << ans << endl;
}