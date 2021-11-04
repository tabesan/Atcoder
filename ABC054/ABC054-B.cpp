#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    for(int i = 0;i < m;i++) {
        cin >> b[i];
    }


    for(int sy = 0;sy <= n - m;sy++){
        for(int sx = 0;sx <= n - m;sx++){
            bool ok = true;
            for(int y = 0;y < m;y++){
                for(int x = 0;x < m;x++){
                    if (a[sy + y][sx + x] != b[y][x]) ok = false;
                }
            }
            if (ok) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}