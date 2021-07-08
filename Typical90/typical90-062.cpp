#include "bits/stdc++.h"
using namespace std;

int main(){
   int n;
   cin >> n;
   vector<vector<int>> g(n + 1);
   vector<bool> usable(n + 1, false);
   queue<int> q;
   for(int i = 1;i <= n;i++){
       int a, b;
       cin >> a >> b;
       g[a].push_back(i);
       g[b].push_back(i);
       if (a == i || b == i){
            usable[i] = true;
            q.push(i);
       }
   }

   vector<int> num;
   while(!q.empty()){
       int p = q.front();
       q.pop();
       num.push_back(p);
       for(auto v : g[p]){
           if (usable[v]) continue;
           usable[v] = true;
           q.push(v);
       }
   }

   reverse(num.begin(), num.end());

   if (num.size() != n){
       cout << -1 << endl;
   } else {
       for(auto v : num) {
           cout << v << endl;
       }
   }


}