#include "bits/stdc++.h"
using namespace std;
const long long INF = 1e9;

int main(){
    int n;
    cin >> n;
    vector<int> h(n + 1);
    for(int i = 1;i <= n;i++) cin >> h[i];

    vector<long long> dp(n + 1, INF);
    dp[1] = 0;
    for(int i = 2;i <= n;i++){
        dp[i] = min(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
        if (i > 2){
            dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
        }
    }

    cout << dp[n] << endl;
}