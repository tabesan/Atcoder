#include "bits/stdc++.h"
using namespace std;
const long long INF = 1e9;
const long long MOD = 1e9 + 7;

int main(){
    int n, m;
    cin >> n >> m;
    if (m == 0){
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int>> g(n + 1);
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<long long> dist(n + 1, 1e18);
    vector<long long> num(n + 1, 0);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
    dist[1] = 0;
    num[1] = 1;
    q.push({0, 1});
    while(!q.empty()){
        auto p = q.top();
        q.pop();
        if (dist[p.second] < p.first) continue;
        for(auto v : g[p.second]){
            if (dist[v] > dist[p.second] + 1){
                dist[v] = dist[p.second] + 1;
                num[v] = num[p.second];
                q.push({dist[v], v});
            } else if (dist[v] == dist[p.second] + 1){
                num[v] += num[p.second];
                num[v] %= MOD;
            }
        }
    }

    long long mini = dist[n];
    if (mini == 1e18){
        cout << 0 << endl;
        return 0;
    } else {
        cout << num[n] << endl;
        return 0;
    }   
}