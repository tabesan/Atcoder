#include "bits/stdc++.h"
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<long long>> c(10, vector<long long>(10));
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            cin >> c[i][j];
        }
    }

    vector<vector<int>> a(h, vector<int>(w));
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            for(int k = 0;k < 10;k++){
                c[j][k] = min(c[j][k], c[j][i] + c[i][k]);                
            }
        }
    }

    long long ans = 0;
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            if (a[i][j] >= 0){
                ans += c[a[i][j]][1];
            }
        }
    }

    cout << ans << endl;
}