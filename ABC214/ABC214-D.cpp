#include "bits/stdc++.h"
using namespace std;

struct UnionFind {
    vector<int> d;
    UnionFind(int n=0) : d(n,-1){}
    int Find (int x){//根の番号を探す
        if(d[x] < 0) return x;
        return d[x] = Find(d[x]);
    }
    bool unite (int x, int y){
        x = Find(x); y = Find(y);
        if(x == y ) return false;
        if(d[x] < d[y]){
            swap(x,y);
        }
        d[x] += d[y];
        d[y] = x;
        return true;
    } 
    bool same(int x, int y){
        return Find(x) == Find(y);
    }
    int size(int x) {
        return (-d[Find(x)]);
    }
};

int main(){
    int n;
    cin >> n;

    vector<tuple<int, int, int>> tp(n - 1);
    for(int i = 0;i < n - 1;i++){
        int u, v, w;
        cin >> u >> v >> w;
        tp[i] = make_tuple(w, u, v);
    }
    sort(tp.begin(), tp.end());
    
    UnionFind uf(n);
    long long ans = 0;
    for(int i = 0;i < n - 1;i++){
        auto& [w, u, v] = tp[i];
        ans += (long long) w * uf.size(u) * uf.size(v);
        uf.unite(u, v);
    }

    cout << ans << endl;
}