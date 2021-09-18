#include "bits/stdc++.h"
using namespace std;

int dp[310][1000][1000];
int main(){
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n + 1), b(n + 1);
    int sumTako = 0, sumTai = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> b[i];
        sumTako += a[i];
        sumTai += b[i];
    }

    if (sumTako < x || sumTai < y) {
        cout << -1 << endl;
        return 0;
    }

    for(int i = 0;i <= 300;i++){
        for(int j = 0;j <= 300;j++){
            for(int k = 0;k <= 300;k++){
                dp[i][j][k] = INF;
            }
        }
    }

    dp[0][0][0] = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= 300;j++){
            for(int k = 0;k <= 300;k++){
                dp[i][min(j + a[i], x)][min(k + b[i], y)] = 
                    min(dp[i][min(j + a[i], x)][min(k + b[i], y)], dp[i - 1][j][k] + 1);
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
            }
        }
    }

    cout << dp[n][x][y] << endl;
}