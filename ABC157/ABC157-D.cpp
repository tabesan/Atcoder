#include "bits/stdc++.h"
using namespace std;

struct UnionFind {
    vector<int> d;
    UnionFind(int n=0) : d(n,-1){}
    int Find (int x){
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
    int n, m, k;
    cin >> n >> m >> k;
    UnionFind uf(n);
    vector<int> a(m), b(m), c(k), d(k);
    for(int i = 0;i < m;i++){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        uf.unite(a[i], b[i]);
    }

    for(int i = 0;i < k;i++){
        cin >> c[i] >> d[i];
        c[i]--; d[i]--;
    }

    vector<int> ans(n); 
    for(int i = 0;i < n;i++){
        ans[i] = uf.size(i) - 1; 
    }

    vector<set<int>> friends(n);
    for(int i = 0;i < m;i++){
        ans[a[i]]--;
        ans[b[i]]--;
        friends[a[i]].insert(b[i]);
        friends[b[i]].insert(a[i]);
    }   

    for(int i = 0;i < k;i++){
        if (friends[c[i]].count(d[i]) == 0 && (uf.Find(c[i]) == uf.Find(d[i]))) {
            ans[c[i]]--;
            ans[d[i]]--;
        }
    }

    for(int i = 0;i < n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}