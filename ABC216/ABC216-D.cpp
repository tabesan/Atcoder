#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> idx(n);
    vector<queue<int>> a(m);
    for(int i = 0;i < m;i++){
        int k, A;
        cin >> k;
        for(int j = 0;j < k;j++){
            cin >> A;
            A--;
            a[i].push(A);
        }
        idx[a[i].front()].push_back(i);
    }

    
    queue<int> q;
    for(int i = 0;i < n;i++){
        if (idx[i].size() == 2) {
            q.push(i);
        }
    }

    while(!q.empty()){
        int p = q.front();
        q.pop();

        for(auto v : idx[p]){
            a[v].pop();
            if (!a[v].empty()){
                idx[a[v].front()].push_back(v);
                if (idx[a[v].front()].size() == 2) {
                    q.push(a[v].front());
                }
            }
        }
    }

    for(auto v : a){
        if (!v.empty()){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}