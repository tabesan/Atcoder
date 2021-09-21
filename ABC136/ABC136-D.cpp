#include "bits/stdc++.h"
using namespace std;

int dp[40][100010];
int main(){
    string s;
    cin >> s;
    for(int i = 0;i < s.size();i++){
        if (s[i] == 'R') dp[0][i] = i + 1;
        else dp[0][i] = i - 1;
    }

    for(int p = 0;p < 32;p++){
        for(int i = 0;i < s.size();i++) {
            dp[p + 1][i] = dp[p][dp[p][i]];
        }
    }

    vector<int> ans(s.size() + 1);
    for(int i = 0;i < s.size();i++){
        ans[dp[32][i]]++;
    }

    for(int i = 0;i < s.size();i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}