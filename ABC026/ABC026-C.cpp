#include "bits/stdc++.h"
using namespace std;

int dfs(int pos, vector<vector<int>> &g) {
    if (g[pos].size() == 0) {
        return 1;
    }

    int min_pay = 1e9, max_pay = 0;
    for(auto v : g[pos]) {
        int pay = dfs(v, g);
        min_pay = min(min_pay, pay);
        max_pay = max(max_pay, pay);
    }

    return min_pay + max_pay + 1;
}

int main(){
    int n;
    cin >> n;
    vector<int> b(n - 1);
    vector<vector<int>> g(n);
    for(int i = 0;i < n - 1;i++){
        cin >> b[i];
        b[i]--;
        g[b[i]].push_back(i + 1);
    }

    cout << dfs(0, g) << endl;    
}