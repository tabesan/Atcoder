#include "bits/stdc++.h"
using namespace std;

int n;
vector<long long> dijk(int start, vector<vector<pair<int, int>>> &g){
    vector<long long> dist(n, 1e18);
    dist[start] = 0;
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(auto v : g[p]){
            if (dist[v.first] > dist[p] + v.second) {
                dist[v.first] = dist[p] + v.second;
                q.push(v.first);
            }
        }
    }

    return dist;
}
int main(){
    int m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for(int i = 0;i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    
    auto from1 = dijk(0, g);
    auto fromN = dijk(n - 1, g);
    vector<long long> ans;
    for(int k = 0;k < n;k++){
        ans.push_back(from1[k] + fromN[k]);
    }

    for(auto v : ans){
        cout << v << endl;
    }
}