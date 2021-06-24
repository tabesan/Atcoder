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
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    UnionFind uf(200010);

    for(int i = 0;i < n / 2;i++){
        if (a[i] != a[n - i - 1]) {
            uf.unite(a[i], a[n - i - 1]);
        }
    }

    set<int> st;
    for(int i = 0;i < n;i++){
        st.insert(uf.Find(a[i]));
    }

    int ans = 0;
    for(auto s : st){
        ans += uf.size(s) - 1;
    }

    cout << ans << endl;
}