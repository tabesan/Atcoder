#include "bits/stdc++.h"
using namespace std;
const long long INF = 1e9;

int main(){
    int N, C;
    cin >> N >> C;
    vector<vector<int>> d(C, vector<int>(C));
    for(int i = 0;i < C;i++){
        for(int j = 0;j < C;j++){
            cin >> d[i][j];
        }
    }

    vector<vector<int>> c(N, vector<int>(N));
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            cin >> c[i][j];
            c[i][j]--;
        }
    }   

    vector<vector<int>> pre(3, vector<int>(30, 0));
    for(int i = 0;i < C;i++){
        for(int j = 0;j < N;j++){
            for(int k = 0;k < N;k++){
                pre[(j + k) % 3][i] += d[c[j][k]][i];
            }
        }
    }

    int ans = INF;
    for(int i = 0;i < C;i++){
        for(int j = 0;j < C;j++){
            for(int k = 0;k < C;k++) {
                if (i == j) continue;
                if (i == k) continue;
                if (j == k) continue;

                ans = min(ans, pre[0][i] + pre[1][j] + pre[2][k]);
            }
        }
    }

    cout << ans << endl;


}