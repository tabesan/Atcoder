#include "bits/stdc++.h"
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

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
    int h, w , q;
    cin >> h >> w >> q;
    UnionFind uf((h + 1) * (w + 1));
    vector<vector<int>> g(h + 1, vector<int>(w + 1, 0));
    vector<string> ans;
    for(int i = 0;i < q;i++){
        int t;
        cin >> t;
        if (t == 1){
            int r, c;
            cin >> r >> c;
            int curNode = (r - 1)*w + c;
            g[r][c] = 1;
            for(int j = 0;j < 4;j++){
                int y = r + dy[j];
                int x = c + dx[j];
                if (x >= 1 && x <= w && y >= 1 && y <= h && g[y][x] == 1){
                    int neighbor = (y - 1)*w + x;
                    uf.unite(curNode, neighbor);
                }
            }
        } else if (t == 2) {
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            int nodeA = (ra - 1)*w + ca;
            int nodeB = (rb - 1)*w + cb; 
            if (g[ra][ca] && g[rb][cb] && uf.same(nodeA, nodeB)) {
                ans.push_back("Yes");
            } else {
                ans.push_back("No");
            }
        }
    }

    for(auto v : ans){
        cout << v << endl;
    }
}