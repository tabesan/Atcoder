#include "bits/stdc++.h"
#include<sstream>
using namespace std;
const long long INF = 1e9;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0;i < h;i++){
        cin >> s[i];
    }

    vector<vector<bool>> seen(h, vector<bool>(w, false));
    vector<vector<int>> panch(h, vector<int>(w, INF));
    panch[0][0] = 0;
    deque<pair<int, int>> q;
    q.push_back({0, 0});
    while(!q.empty()){
        auto p = q.front();
        q.pop_front();
        if (seen[p.second][p.first]) continue;
        seen[p.second][p.first] = true;

        for(int i = 0;i < 4;i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (s[ny][nx] == '.' && panch[ny][nx] > panch[p.second][p.first]) {
                panch[ny][nx] = panch[p.second][p.first];
                q.push_front({nx, ny});
            }
        }

        for(int i = -2;i <= 2;i++){
            for(int j = -2;j <= 2;j++){
                if (abs(i) + abs(j) == 4) continue;
                int nx = p.first + i;
                int ny = p.second + j;
                if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;

                if (panch[ny][nx] > panch[p.second][p.first]) {
                    panch[ny][nx] = panch[p.second][p.first] + 1;
                    q.push_back({nx, ny});
                }
            }
        }        
    }

    cout << panch[h - 1][w - 1] << endl;
}