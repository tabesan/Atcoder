#include "bits/stdc++.h"
using namespace std;

long long dp[3010][3010];

int main(){
    string s, t;
    cin >> s >> t;

    int S = int(s.size()), T = int(t.size());
    for(int i = 1;i <= S;i++){
        for(int j = 1;j <= T;j++){
            if (s[i - 1] == t[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string ans = "";
    int i = S, j = T;
    int len = dp[i][j];
    while(len > 0){
        if (s[i - 1] == t[j - 1]){
            ans = s[i - 1] + ans;
            i--;
            j--;
            len--;
        } else if (dp[i - 1][j] == dp[i][j]){
            i--;
        } else {
            j--;
        }
    }

    cout << ans << endl;
}