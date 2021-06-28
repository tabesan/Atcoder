#include "bits/stdc++.h"
using namespace std;

long long dp[5010][5010];
int main(){
    int n;
    cin >> n;
    vector<long long> d(n), c(n), s(n);
    vector<tuple<long long, long long, long long>> t;
    for(int i = 0;i < n;i++){
        cin >> d[i] >> c[i] >> s[i];
        t.push_back(make_tuple(d[i], c[i], s[i]));
    }

    sort(t.begin(), t.end());

    for(int i = 0;i < n;i++){
        d[i] = get<0>(t[i]);
        c[i] = get<1>(t[i]);
        s[i] = get<2>(t[i]);
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j <= 5000;j++){
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j + c[i] <= d[i]){
                dp[i + 1][j + c[i]] = max(dp[i + 1][j + c[i]], dp[i][j] + s[i]);
            }
        }
    }

    long long ans = 0;
    for(int i = 0;i <= 5000;i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}