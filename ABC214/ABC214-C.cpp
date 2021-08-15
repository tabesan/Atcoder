#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> s(n + 1), t(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> s[i];
    }
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
    for(int i = 1;i <= n;i++){
        cin >> t[i];
        q.push({t[i], i});
    }

    vector<long long> ans(n + 1, -1);
    int cnt = 0;
    int nx = q.top().second;
    while(!q.empty()){
        auto p = q.top();
        q.pop();
        if (p.second == n){
            nx = 1;
        } else if (p.second < n) {
            nx = p.second + 1;
        }
        
        if (ans[p.second] == -1){
            ans[p.second] = p.first;
            cnt++;
            q.push({p.first + s[p.second], nx});
        }
        if (cnt == n) break;
    }

    for(int i = 1;i <= n;i++){
        cout << ans[i] << endl;
    }
}