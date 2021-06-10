#include "bits/stdc++.h"
using namespace std;

int n;
vector<int> res1, res2;

void dfs(int pos, int color, int par, vector<vector<int>> &g){
    for(auto nx : g[pos]){
        if (nx != par){
            if (color == 0) res1.push_back(nx);
            else res2.push_back(nx);
            dfs(nx, 1 - color, pos, g);
        }
    }

}

int main(){
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0;i < n - 1;i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }    

    dfs(0, 0, -1, g);

    if (res1.size() >= n/2){
        for(int i = 0;i < n/2;i++){
            cout << res1[i] + 1 << " ";
        }
    } else {
        for(int i = 0;i < n/2;i++){
            cout << res2[i] + 1 << " ";
        }
    }
    cout << endl;

}