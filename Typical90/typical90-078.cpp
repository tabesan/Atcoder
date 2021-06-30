#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<int> q;
    q.push(0);
    set<int> st;
    vector<bool> used(n);
    while(!q.empty()){
        int p = q.front();
        q.pop();
        if(used[p]){
            continue;
        }
        int cnt = 0;
        used[p] = true;
        for(auto nx : g[p]){
            if (nx < p){
                cnt++;
            }
            q.push(nx);
        }
        if (cnt == 1){
            st.insert(p);
        }
    }

    cout << st.size() << endl;
}