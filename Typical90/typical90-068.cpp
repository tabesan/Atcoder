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
    int n, q;
    cin >> n >> q;
    vector<int> t(q), x(q), y(q), v(q);
    for(int i = 0;i < q;i++){
        cin >> t[i] >> x[i] >> y[i] >> v[i];
        x[i]--;
        y[i]--;
    }

    vector<int> sum(n - 1, 0);
    for(int i = 0;i < q;i++){
        if (t[i] == 0) {
            sum[x[i]] = v[i];
        }
    }

    vector<long long> p(n, 0);
    for(int i = 0;i < n - 1;i++){
        p[i + 1] = sum[i] - p[i];
    }
    
    UnionFind uf(n);
    for(int i = 0;i < q;i++){
        if (t[i] == 0){
            uf.unite(x[i], y[i]);
        } else {
            if (!uf.same(x[i], y[i])) {
                cout << "Ambiguous" << endl;
            } else if ((x[i] + y[i]) % 2 == 0) {
                cout << v[i] + (p[y[i]] - p[x[i]]) << endl;
            } else {
                cout << (p[x[i]] + p[y[i]]) - v[i] << endl;
            }
        }
    }
}