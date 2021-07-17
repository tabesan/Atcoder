#include "bits/stdc++.h"
using namespace std;

struct Topological {
    vector<vector<int>> e;
    Topological(int N) {e.resize(N);};
    
    void add_edge(int a, int b){
        e[a].push_back(b);
    }

    bool visit(int v, vector<int> &order, vector<int> &color) {
        color[v] = 1;
        for(auto nx : e[v]) {
            if (color[nx] == 2) continue;
            if (color[nx] == 1) return false;
            if (!visit(nx, order, color)) return false;
        }
        order.push_back(v);
        color[v] = 2;
        return true;
    }

    bool sort(vector<int> &order) {
        int n = e.size();
        vector<int> color(n);
        for(int i = 0;i < n;i++) {
            if (!color[i] && !visit(i, order, color)) {
                return false;
            }
        }
        reverse(order.begin(), order.end());
        return true;
    }
};

long long dp[100010];

int main(){
    int n, m;
    cin >> n >> m;
    Topological ts(n);
    vector<vector<int>> g(n);
    for(int i = 0;i < m;i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        ts.add_edge(x, y);
        g[x].push_back(y);
    }  
    vector<int> ord;
    ts.sort(ord);

    for(auto node : ord) {
        for(auto to : g[node]) {
            dp[to] = max(dp[to], dp[node] + 1);
        }
    }

    long long ans = 0;
    for(int i = 0;i < n;i++ ) ans = max(ans, dp[i]);
    cout << ans << endl;
}