#include "bits/stdc++.h"
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int h, w;
bool seen[20][20];
char c[20][20];
int dfs(int sx, int sy, int px, int py) {
    if (sx == px && sy == py && seen[py][px]) return 0;
    seen[py][px] = true;

    int res = -100000;
    for(int i = 0;i < 4;i++){
        int nx = px + dx[i];
        int ny = py + dy[i];
        if (nx < 0 || nx >= w || ny < 0 || ny >= h || c[ny][nx] == '#') continue;
        if ((sx != nx || sy != ny) && seen[ny][nx]) continue;
        int tmp = dfs(sx, sy, nx, ny);
        res = max(res, tmp + 1);
    }
    seen[py][px] = false;
    return res;
}

int main(){
    cin >> h >> w;
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            cin >> c[i][j];
        }
    }

    int ans = -1;
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            ans = max(ans, dfs(j, i, j, i));
        }
    }

    if (ans <= 2) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}