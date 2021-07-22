#include "bits/stdc++.h"
using namespace std;

template<typename T> vector<vector<T>> rotate(vector<vector<T>> g){
    int y = g.size();
    int x = g[0].size();
    vector<vector<T>> graph(x, vector<T>(y));
    for(int i = 0;i < y;i++){
        for(int j = 0;j < x;j++){
            graph[j][y - i - 1] = g[i][j];
        }
    }

    return graph;
}

int h, w, c;
vector<vector<int>> a;

long long mini[1010][1010];

long long func() {
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            mini[i][j] = a[i][j] - 1LL*c*(i + j);
        }
    }

    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            if (i > 0) mini[i][j] = min(mini[i][j], mini[i - 1][j]);
            if (j > 0) mini[i][j] = min(mini[i][j], mini[i][j - 1]);
        }
    }

    long long out = 1e18;
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            long long res = 1e18;
            if (i > 0) res = min(res, mini[i - 1][j]);
            if (j > 0) res = min(res, mini[i][j - 1]);
            out = min(out, a[i][j] + 1LL*c*(i + j) + res);
        }
    }

    return out;
}

int main(){
    cin >> h >> w >> c;
    a.resize(h);

    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++) {
            int A;
            cin >> A;
            a[i].push_back(A);
        }
    }

    long long ans = 1e18;
    for(int i = 0;i < 2;i++){
        ans = min(ans, func());
        a = rotate(a);
        swap(h, w);
    }

    cout << ans << endl;
}