#include "bits/stdc++.h"
using namespace std;

int DX[2] = {1, 0};
int DY[2] = {0, 1};

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for(int i = 0;i < h;i++) {
        cin >> a[i];
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    seen[0][0] = true;
    seen[h - 1][w - 1] = true;

    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        for(int i = 0;i < 2;i++) {
            int nx = p.first + DX[i];
            int ny = p.second + DY[i];
            if (nx >= 0 && nx < w && ny >= 0 && ny < h && a[ny][nx] == '#') {
                seen[ny][nx] = true;
                q.push({nx, ny});
                break;
            }
        }
    }

    for(int i = 0;i < h;i++) {
        for(int j = 0;j < w;j++) {
            if (!seen[i][j] && a[i][j] == '#') {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    cout << "Possible" << endl;
}