#include "bits/stdc++.h"
using namespace std;

const long long INF = 1e9;
int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp(h, vector<int>(w));
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            dp[i][j] = ((i + j) % 2 == 1 ? INF : -INF);
        }
    }

    dp[h - 1][w - 1] = 0;
    for(int i = h - 1;i >= 0;i--){
        for(int j = w - 1;j >= 0;j--){
            int v = (a[i][j] == '+' ? 1 : -1);
            if ((i + j) % 2 == 0){
                if (i - 1 >= 0) {
                    dp[i - 1][j] = min(dp[i - 1][j], dp[i][j] - v);
                }
                if (j - 1 >= 0){
                    dp[i][j - 1] = min(dp[i][j - 1], dp[i][j] - v);
                }
            } else {
                if (i - 1 >= 0){
                    dp[i - 1][j] = max(dp[i - 1][j], dp[i][j] + v);
                }
                if (j - 1 >= 0){
                    dp[i][j - 1] = max(dp[i][j - 1], dp[i][j] + v);
                }
            }
        }
    }
    

    if (dp[0][0] > 0) cout << "Takahashi" << endl;
    else if (dp[0][0] == 0) cout << "Draw" << endl;
    else cout << "Aoki" << endl;
}