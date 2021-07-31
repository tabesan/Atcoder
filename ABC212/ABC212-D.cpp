#include "bits/stdc++.h"
using namespace std;

int main(){
    int q;
    cin >> q;
    priority_queue<long long,vector<long long>,greater<long long>> que;
    long long sum = 0, x;
    int p;
    vector<long long> ans;
    for(int i = 0;i < q;i++){
        cin >> p;
        if (p == 1){
            cin >> x;
            que.push(x - sum);
        } else if (p == 2){
            cin >> x;
            sum += x;
        } else {
            x = que.top();
            que.pop();
            ans.push_back(x + sum);
        }
    }

    for(auto a : ans){
        cout << a << endl;
    }
}