#include "bits/stdc++.h"
using namespace std;

bool used[100010];
vector<int> f;
long long cnt = 0;

void dfs(int pos, vector<vector<int>> &g){
    used[pos] = true;
    for(auto v : g[pos]){
        if (used[v] == false){
            dfs(v, g);
        }
    }

    f.push_back(pos);
}

void dfs2(int pos, vector<vector<int>> &g){
    used[pos] = true;
    cnt++;
    for(auto v : g[pos]){
        if (used[v] == false) dfs2(v, g);
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> forward(n), back(n);
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        forward[a].push_back(b);
        back[b].push_back(a);
    }

    for(int i = 0;i < n;i++){
        if (used[i] == false){
            dfs(i, forward);
        }
    }
    
    long long ans = 0;
    for(int i = 0;i < n;i++){
        used[i] = false;
    }

    reverse(f.begin(), f.end());
    for(auto v : f){
        if (used[v] == true) continue;
        cnt = 0;
        dfs2(v, back);
        ans += cnt*(cnt - 1LL) / 2LL;
    }

    cout << ans << endl;
}