#include "bits/stdc++.h"
using namespace std;
const long long MOD = 1e9 + 7;

long long dp[100010];
bool broke[100010];
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i = 1;i <= m;i++) {
        cin >> a[i];
        broke[a[i]] = true;
    }

    dp[0] = 1;
    for(int i = 1;i <= n;i++) {
        if (broke[i]) continue;

        dp[i] += dp[i - 1];
        dp[i] %= MOD;

        if (i - 2 >= 0) {
            dp[i] += dp[i - 2];
            dp[i] %= MOD;
        }
    }

    cout << dp[n] << endl;
}