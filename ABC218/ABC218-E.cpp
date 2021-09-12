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
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    vector<tuple<long long, int, int>> tp(m);
    long long sum = 0;
    for(int i = 0;i < m;i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--; b--;
        tp[i] = make_tuple(c, a, b);
        sum += c;
    }
    
    sort(tp.begin(), tp.end());
    for(int i = 0;i < m;i++){
        int x = get<1>(tp[i]), y = get<2>(tp[i]);
        if (x > y) swap(x, y);
        if (get<0>(tp[i]) < 0) {
            sum -= get<0>(tp[i]);
            uf.unite(x, y);
        } else if (uf.Find(x) != uf.Find(y)){
            uf.unite(x, y);
            sum -= get<0>(tp[i]);
        }
    }

    cout << sum << endl;
}