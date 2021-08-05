#include "bits/stdc++.h"
using namespace std;

vector<int> num[100010];
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
    vector<int> p(n);
    for(int i = 0;i < n;i++){
        cin >> p[i];
        p[i]--;
    }

    UnionFind uf(n);

    for(int i = 0;i < m;i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        uf.unite(x, y);
    }

    set<int> st;
    for(int i = 0;i < n;i++) {
        num[uf.Find(i)].push_back(i);
        st.insert(uf.Find(i));
    }

    int ans = 0;
    vector<int> exist(n, 0);
    for(auto i : st){
        if (num[i].size() == 0) continue;
        for(auto v : num[i]){
            exist[p[v]] = 1;
        }

        for(auto v : num[i]){
            if (exist[v]){
                ans++;
            }
        }

        for(auto v : num[i]){
            exist[p[v]] = 0;
        }
    }

    cout << ans << endl;
}