#include "bits/stdc++.h"
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w)), b(h, vector<int>(w));
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            cin >> b[i][j];
        }
    }

    long long ans = 0;
    int Dx[4] = {0, 1, 0, 1};
    int Dy[4] = {0, 0, 1, 1};
    for(int i = 0;i < h - 1;i++){
        for(int j = 0;j < w - 1;j++){
            int v = b[i][j] - a[i][j];
            for(int k = 0;k < 4;k++){
                a[i + Dx[k]][j + Dy[k]] += v;
            }
            ans += abs(v);
        }
    }

    bool ok = true; 
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            if (a[i][j] != b[i][j]){
                ok = false;
                break;
            }
        }
    }

    if (ok){
        cout << "Yes" << endl;
        cout << ans << endl;
    } else {
        cout << "No" << endl;
    }
}