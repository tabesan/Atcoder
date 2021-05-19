
#include "bits/stdc++.h"
#include<sstream>
using namespace std;
typedef long long ll;
#define _USE_MATH_DEFINES
#include <math.h>
#define NIL = -1;
#define all(x) x.begin(),x.end()
const ll INF = 1e9;
const long long inf = 1e18;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int dist[1010][1010][4];

struct status {
    int x, y, dir;
};

int main(){
    int h, w;
    cin >> h >> w;
    int rs, cs, rt, ct;
    cin >> rs >> cs >> rt >> ct;
    rs--;
    cs--;
    rt--;
    ct--;
    vector<string> s(h);
    for(int i = 0;i < h;i++){
        cin >> s[i];
    }

    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            for(int k = 0;k < 4;k++){
                dist[i][j][k] = INF;
            }
        }
    }

    deque<status> q;
    for(int i = 0;i < 4;i++){
        dist[rs][cs][i] = 0;
        q.push_back({cs, rs, i});
    }

    while(!q.empty()) {
        auto p = q.front();
        q.pop_front();
        for(int i = 0;i < 4;i++){
            int ny = p.y + dy[i];
            int nx = p.x + dx[i];
            int cost = dist[p.y][p.x][p.dir] + (i != p.dir);
            if (ny < h && ny >= 0 && nx < w && nx >= 0 && s[ny][nx] == '.'){
                if (dist[ny][nx][i] > cost) {
                    dist[ny][nx][i] = cost;
                    if (p.dir != i) q.push_back({nx, ny, i});
                    else q.push_front({nx, ny, i});
                }
            }
        }
    }

    int ans = INF;
    for(int i = 0;i < 4;i++){
        ans = min(ans, dist[rt][ct][i]);
    }

    cout << ans << endl;
    return 0;
}