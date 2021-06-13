#include "bits/stdc++.h"
using namespace std;

class segment_tree {
private:
    int _size;
    vector<int> seg;
    vector<int> lazy;
    void push(int k){
        if (k < _size) {
            lazy[k * 2] = max(lazy[k * 2], lazy[k]);
            lazy[k * 2 + 1] = max(lazy[k * 2 + 1], lazy[k]);
        }
        seg[k] = max(seg[k], lazy[k]);
        lazy[k] = 0;
    }
    void update(int a, int b, int x, int k, int l, int r) {
        push(k);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] = x;
            push(k);
            return;
        }
        update(a, b, x, k * 2, l, (l + r) >> 1);
        update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
        seg[k] = max(seg[k * 2], seg[k * 2 + 1]);
    }
    int range_max(int a, int b, int k, int l, int r){
        push(k);
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return seg[k];
        int lc = range_max(a, b, k * 2, l, (l + r) >> 1);
        int rc = range_max(a, b, k * 2 + 1, (l + r) >> 1, r);
        return max(lc, rc);
    }
public:
    segment_tree() : _size(0), seg(), lazy() {};
    segment_tree(int N) {
        _size = 1;
        while(_size < N) {
            _size *= 2;
        }
        seg = vector<int>(_size * 2, 0);
        lazy = vector<int>(_size * 2, 0);
    }
    void update(int l, int r, int x){
        update(l, r, x, 1, 0, _size);
    }
    int range_max(int l, int r){
        return range_max(l, r, 1, 0, _size);
    }
};

int main(){
    int w, n;
    cin >> w >> n;
    segment_tree seg(w);
    for(int i = 0;i < n;i++){
        int l, r;
        cin >> l >> r;
        int h = seg.range_max(l - 1, r) + 1;
        seg.update(l - 1, r, h);
        cout << h << endl;
    }
    return 0;
}