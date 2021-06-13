#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> g(1001, vector<int>(1010, 0));
    for(int i = 0;i < n;i++){
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        g[ly][lx]++;
        g[ly][rx]--;
        g[ry][lx]--;
        g[ry][rx]++;
    }

    for(int i = 0;i <= 1000;i++){
        for(int j = 1;j <= 1000;j++){
            g[i][j] += g[i][j - 1];
        }
    }

    for(int i = 0;i <= 1000;i++){
        for(int j = 1;j <= 1000;j++){
            g[j][i] += g[j - 1][i];
        }
    }

    vector<int> ans(n + 1, 0);
    for(int i = 0;i <= 1000;i++){
        for(int j = 0;j <= 1000;j++){
            ans[g[i][j]]++;
        }
    }

    for(int i = 1;i <= n;i++){
        cout << ans[i] << endl;
    }
}