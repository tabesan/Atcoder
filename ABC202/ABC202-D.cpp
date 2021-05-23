#include "bits/stdc++.h"
using namespace std;

int main(){
    long long a, b, k;
    cin >> a >> b >> k;
    vector<vector<long long>> dp(a + 1, vector<long long>(b + 1, 0));
    dp[0][0] = 1;
    for(int i = 0;i <= a;i++){
        for(int j = 0;j <= b;j++){
            if (i > 0){
                dp[i][j] += dp[i - 1][j];
            }
            if (j > 0){
                dp[i][j] += dp[i][j - 1];
            }
        }
    }

    string ans = "";
    while(a > 0 && b > 0) {
        if (k <= dp[a - 1][b]){
            ans = ans + 'a';
            a--;
        } else {
            k -= dp[a - 1][b];
            ans = ans + 'b';
            b--;
        }
    }
    ans += string(a, 'a');
    ans += string(b, 'b');
    cout << ans << endl;
}