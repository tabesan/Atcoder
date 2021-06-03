#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, s;
    cin >> n >> s;
    vector<long long> a(n), b(n);
    for(int i = 0;i < n;i++){
        cin >> a[i] >> b[i];
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(s + 1, false));
    dp[0][0] = true;
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= s;j++){
            if (j >= a[i] && dp[i][j - a[i]]) dp[i + 1][j] = true;
            if (j >= b[i] && dp[i][j - b[i]]) dp[i + 1][j] = true;
        }
    }

    if (!dp[n][s]) {
        cout << "Impossible" << endl;
    } else {
        string ans(n, '*');
        int pos = s;
        for(int i = n - 1;i >= 0;i--){
            if (pos >= a[i] && dp[i][pos - a[i]]) {
                ans[i] = 'A';
                pos -= a[i];
            } else {
                ans[i] = 'B';
                pos -= b[i];
            }
        }
        cout << ans << endl;
    }

    return 0;
}