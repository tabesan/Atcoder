#include "bits/stdc++.h"
using namespace std;

int main(){
    const long long m = 998244353;
    int n;
    cin >> n;
    vector<pair<long long, long long>> ab(n);
    for(int i = 0;i < n;i++){
        cin >> ab[i].first;
    }
    for(int i = 0;i < n;i++){
        cin >> ab[i].second;
    }
    sort(ab.begin(), ab.end());

    long long ans = 0;
    vector<vector<long long>> dp(n + 1, vector<long long>(5010));
    dp[0][0] = 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= 5000;j++){
            dp[i + 1][j] += dp[i][j]; // i番目の要素を選ばないとき
            if (j + ab[i].second <= 5000){ // i番目の要素を選ぶとき
                dp[i + 1][j + ab[i].second] += dp[i][j];
                dp[i + 1][j + ab[i].second] %= m;
            }
            if (j + ab[i].second <= ab[i].first){ // i番目の要素を選んでも和がA[i]を超えないとき
                ans += dp[i + 1][j + ab[i].second];
                ans %= m;
            }
        }
    }

    cout << ans << endl;
}