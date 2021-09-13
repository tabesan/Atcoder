#include "bits/stdc++.h"
using namespace std;

int main(){
    int q;
    cin >> q;
    priority_queue<int, vector<int>, greater<int>> que;
    queue<int> qq;
    vector<int> ans;
    for(int i = 0;i < q;i++){
        int c;
        cin >> c;
        if (c == 1){
            int x;
            cin >> x;
            qq.push(x);
        } else if (c == 2){
            if (!que.empty()) {
                ans.push_back(que.top());
                que.pop();
            } else {
                ans.push_back(qq.front());
                qq.pop();
            }
        } else {
            while(!qq.empty()){
                que.push(qq.front());
                qq.pop();
            }
        }
    }

    for(auto a : ans){
        cout << a << endl;
    }
}