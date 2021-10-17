#include "bits/stdc++.h"
using namespace std;
const long long INF = 1e9;
int n, m;
vector<int> h;
vector<int> ans;
void topo(vector<vector<int>> &g) {
    priority_queue<int, vector<int>, greater<>> q;
    for(int i = 0;i < n;i++){
        if (h[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int p = q.top();
        q.pop();
        ans.push_back(p);

        for(auto v : g[p]) {
            h[v]--;
            if (h[v] == 0){
                q.push(v);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    int mini = INF;
    vector<int> a(m), b(m);
    h.resize(n, 0);
    for(int i = 0;i < m;i++){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        mini = min(mini, a[i]);
        h[b[i]]++;
    }

    vector<vector<int>> g(n);
    for(int i = 0;i < m;i++){
        g[a[i]].push_back(b[i]);
    }

    priority_queue<int, vector<int>, greater<>> q;
    vector<bool> seen(n);
    bool loop = false;
    for(int i = 0;i < m;i++){
        if (seen[a[i]]) continue;
        int start = a[i];
        q.push(a[i]);
        while(!q.empty()) {
            auto p = q.top();
            q.pop();
            for(auto v : g[p]) {
                if (v == start) {
                    loop = true;
                }
                if (seen[v]) continue;
                seen[v] = true;
                q.push(v);
            }
        }
    }

    topo(g);
    if (ans.size() == n) {
        for(auto v : ans){
            cout << v + 1<< " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}