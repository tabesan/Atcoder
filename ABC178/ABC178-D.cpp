#include "bits/stdc++.h"
using namespace std;
const long long MOD = 1e9 + 7;

int main(){
    int s;
    cin >> s;
    vector<long long> dp(s + 1);

    dp[0] = 1;
    for(int i = 1;i <= s;i++){
        for(int j = 3;j <= s;j++){
            if (i - j >= 0){
                dp[i] += dp[i - j];
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[s] << endl;
}