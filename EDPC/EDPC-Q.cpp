#include "bits/stdc++.h"
using namespace std;

#define defo 0
template<class V, int NV> struct segmentTree { //[l,r)
    V comp(V& l, V& r) { return max(l, r); };
 
    vector<V> val; segmentTree() { val = vector<V>(NV * 2, defo); }
    V get(int x, int y, int l = 0, int r = NV, int k = 1) {
        if (r <= x || y <= l)return defo; if (x <= l && r <= y)return val[k];
        auto a = get(x, y, l, (l + r) / 2, k * 2); 
        auto b = get(x, y, (l + r) / 2, r, k * 2 + 1);
        return comp(a, b);
    }
    void update(int i, V v) {
        i += NV; val[i] = v;
        while (i>1) i >>= 1, val[i] = comp(val[i * 2], val[i * 2 + 1]);
    }
    void add(int i, V v) { update(i, val[i + NV] + v); }
    V operator[](int x) { return get(x, x + 1); }
};

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    vector<long long> a(n);
    for(int i = 0;i < n;i++){
        cin >> h[i];
    }
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    
    segmentTree<long long, 1 << 18> sg;

    for(int i = 0;i < n;i++){
        long long tmp = sg.get(0, h[i]) + a[i];
        sg.update(h[i], max(sg[h[i]], tmp));
    } 

    cout << sg.get(0, 1 << 18) << endl;
}