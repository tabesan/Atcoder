#include "bits/stdc++.h"
using namespace std;
const long long INF = 1e9;

int main(){
    int n;
    cin >> n;
    vector<int> c(n);
    deque<int> q;
    for(int i = 0;i < n;i++){
        cin >> c[i];
    }

    vector<int> dp(n + 1, INF);
    dp[0] = -INF;

    for(int i = 0;i < n;i++){
        auto pos = lower_bound(dp.begin(), dp.end(), c[i]) - dp.begin();
        dp[pos] = c[i];
    }

    int ans = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
    cout << n - ans + 1 << endl;
}   