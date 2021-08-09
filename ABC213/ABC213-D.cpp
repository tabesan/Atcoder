#include "bits/stdc++.h"
#include<sstream>
using namespace std;

vector<int> ans;
void dfs(int pos, int pre, vector<vector<int>> &g){
    ans.push_back(pos);
    for(auto v : g[pos]){
        if (v == pre) continue;
        dfs(v, pos, g);
        ans.push_back(pos);
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0;i < n - 1;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 0;i < n;i++){
        if (g[i].size() == 0) continue;
        sort(g[i].begin(), g[i].end());
    }

    dfs(0, -1, g);
    for(auto a : ans){
        cout << a + 1 << " ";
    }
    cout << endl;
}