#include "bits/stdc++.h"
using namespace std;

long long dp[110][100010];

int main(){
    long long N, W;
    cin >> N >> W;
    vector<long long> w(N + 1), v(N + 1);
    for(int i = 1;i <= N;i++){
        cin >> w[i] >> v[i];
    }

    for(int i = 0;i < 110;i++){
        for(int j = 0;j < 100010;j++){
            dp[i][j] = 1e18;
        }
    }

    dp[0][0] = 0;
    for(int i = 1;i <= N;i++){
        for(int j = 0;j <= 100000;j++){
            if (j - v[i] >= 0){
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    long long ans = 100000;
    while(dp[N][ans] > W){
        ans--;
    }
    cout << ans << endl;
}