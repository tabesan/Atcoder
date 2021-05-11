#include "bits/stdc++.h"
#include<sstream>
using namespace std;
typedef long long ll;
#define _USE_MATH_DEFINES
#include <math.h>
#define NIL = -1;
#define all(x) x.begin(),x.end()
const ll INF = 1e9;
const long long inf = 1e18;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;

int n;
vector<int> dijk(int start, vector<vector<int>> &g){
    vector<int> dist(n, INF);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(auto nx : g[p]){
            if (dist[nx] > dist[p] + 1) {
                dist[nx] = dist[p] + 1;
                q.push(nx);
            }
        }
    }

    return dist;
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

    auto res1 = dijk(0, g);
    int mxLenIdx = max_element(res1.begin(), res1.end()) - res1.begin();
    auto res2 = dijk(mxLenIdx, g);
    auto ans = *max_element(res2.begin(), res2.end());
    cout << ans  + 1 << endl;
}