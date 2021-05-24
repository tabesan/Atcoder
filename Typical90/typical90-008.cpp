#include "bits/stdc++.h"
using namespace std;

const long long MOD = 1e9 + 7;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<long long>> dp(n + 1, vector<long long>(8, 0));
    dp[0][0] = 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= 7;j++){
            dp[i + 1][j] += dp[i][j];
            if (s[i] == 'a' && j == 0) dp[i + 1][j + 1] += dp[i][j];
            if (s[i] == 't' && j == 1) dp[i + 1][j + 1] += dp[i][j];
            if (s[i] == 'c' && j == 2) dp[i + 1][j + 1] += dp[i][j];
            if (s[i] == 'o' && j == 3) dp[i + 1][j + 1] += dp[i][j];
            if (s[i] == 'd' && j == 4) dp[i + 1][j + 1] += dp[i][j];
            if (s[i] == 'e' && j == 5) dp[i + 1][j + 1] += dp[i][j];
            if (s[i] == 'r' && j == 6) dp[i + 1][j + 1] += dp[i][j];
        }
        for(int j = 0;j <= 7;j++){
            dp[i + 1][j] %= MOD;
        }
    }

    cout << dp[n][7] << endl;


}