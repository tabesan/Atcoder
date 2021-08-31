#include "bits/stdc++.h"
using namespace std;

vector<int> ans;
int cnt[100010], c[100010];
void dfs(int pos, int par, vector<vector<int>> &g){
    if (cnt[c[pos]] == 0) ans.push_back(pos + 1);
    cnt[c[pos]]++;

    for(auto v : g[pos]){
        if (v == par) continue;
        dfs(v, pos, g);
    }

    cnt[c[pos]]--;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0;i < n;i++){
        cin >> c[i];
    }
    for(int i = 0;i < n - 1;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0, -1, g);

    sort(ans.begin(), ans.end());
    for(auto a : ans){
        cout << a << endl;
    }
}