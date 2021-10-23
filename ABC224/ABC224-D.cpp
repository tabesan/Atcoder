#include "bits/stdc++.h"
using namespace std;

int main(){
    int m;
    cin >> m;

    vector<vector<int>> g(10);
    for(int i = 0;i < m;i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    string s = "999999999";
    vector<int> p(9);
    for(int i = 1;i <= 8;i++){
        cin >> p[i];
        s[p[i] - 1] = i + '0';
    }

    queue<string> q;
    q.push(s);
    map<string, int> mp;
    mp[s] = 0;

    while(!q.empty()) {
        auto p = q.front();
        q.pop();

        int pos;
        for(int i = 0;i < 9;i++){
            if (p[i] == '9') pos = i + 1;
        }

        for(auto v : g[pos]) {
            string tmp = p;
            swap(tmp[v - 1], tmp[pos - 1]);
            if (mp.count(tmp)) continue;
            mp[tmp] = mp[p] + 1;
            q.push(tmp);
        }
    }

    if (mp.count("123456789") == 0) cout << -1 << endl;
    else {
        cout << mp["123456789"] << endl;
    }
}