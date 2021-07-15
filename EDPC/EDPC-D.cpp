#include "bits/stdc++.h"
using namespace std;

long long dp[110][100010];
int main(){
    int N, W;
    cin >> N >> W;
    vector<long long> w(N + 1), v(N + 1);
    for(int i = 1;i <= N;i++){
        cin >> w[i] >> v[i];
    }

    dp[0][0] = 0;
    for(int i = 1;i <= N;i++){
        for(int j = 1;j <= W;j++){
            if (j - w[i] >= 0){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[N][W] << endl;
}