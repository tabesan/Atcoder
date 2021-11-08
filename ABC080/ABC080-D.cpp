#include "bits/stdc++.h"
using namespace std;

int main(){
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }

    vector<vector<int>> g(h, vector<int>(w));
    bool to_right = true;
    int pos = 0;
    int cnt = 0;
    int color = 0;
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            g[i][pos] = color;
            cnt++;
            if (to_right) pos++;
            else pos--;

            if (cnt == a[color]) {
                cnt = 0;
                color++;
            }
        }

        if (pos == w) pos--;
        else if (pos == -1) pos++;

        to_right = 1 - to_right;
    }

    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            cout << g[i][j] + 1 << " ";
        }
        cout << endl;
    }
}   