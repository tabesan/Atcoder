#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, 1000000000));
    for(int i = 1;i <= n;i++){
        dist[i][i] = 0;
    }

    for(int i = 0;i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        dist[a][b] = c;
    }

    long long ans = 0;
    for(int k = 1;k <= n;k++){
        vector<vector<long long>> d(n + 1, vector<long long>(n + 1, 0));
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                d[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                if (d[i][j] != 1000000000){
                    ans += d[i][j];
                }
            }
        }
        dist = d;
    }

    cout << ans << endl;
    
}