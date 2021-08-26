#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> r(n, vector<int>(n, 0));
    for(int i = 0;i < m;i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        r[x][y] = 1;
        r[y][x] = 1;
    }   

    int ans = 0;
    for(int bit = 0;bit < (1 << n);bit++){
        bool ok = true;
        for(int i = 0;i < n - 1;i++){
            for(int j = i + 1;j < n;j++){
                if ((bit & (1 << i)) && (bit & (1 << j)) && !r[i][j]){
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }   
        if (ok){
            ans = max(ans, __builtin_popcount(bit));
        }
    }

    cout << ans << endl;
}