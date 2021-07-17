#include "bits/stdc++.h"
using namespace std;
const long long INF = 1e9;
const long long MOD = 1e9 + 7;

long long dp[1010][1010];

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            dp[i][j] = 0;
        }
    }

    int moveX[2] = {0, 1}, moveY[2] = {1, 0};
    queue<pair<int, int>> q;
    q.push({0, 0});
    dp[0][0] = 1;
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        for(int i = 0;i < 2;i++){
            int nx = p.second + moveX[i];
            int ny = p.first + moveY[i];
            if (ny < h && ny >= 0 && nx < w && nx >= 0 && a[ny][nx] == '.'){
                if (dp[ny][nx] == 0) {
                    q.push({ny, nx});
                }
                dp[ny][nx] += dp[p.first][p.second];
                dp[ny][nx] %= MOD;
            }
        }
    }

    cout << dp[h - 1][w - 1] << endl;
}