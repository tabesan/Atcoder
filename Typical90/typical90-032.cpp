#include "bits/stdc++.h"
#include<sstream>
using namespace std;
typedef long long ll;
#define _USE_MATH_DEFINES
#include <math.h>
#define NIL = -1;
#define all(x) x.begin(),x.end()
const ll INF = 1e9;
const long long inf = 1e18;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;


int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> a[i][j];
        }
    }
    int m;
    cin >> m;
    vector<vector<int>> bad(n, vector<int>(n, 0));
    vector<int> p;
    for(int i = 0;i < n;i++) p.push_back(i);

    for(int i = 0;i < m;i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        bad[x][y] = 1;
        bad[y][x] = 1;
    }
    int ans = INF;
    do {
        bool relation = true;
        int sum = 0;
        for(int i = 0;i < n - 1;i++){
            if (bad[p[i]][p[i + 1]]) relation = false;
        }
        if (!relation) continue;
        for(int i = 0;i < n;i++){
            sum += a[p[i]][i];
        }
        ans = min(ans, sum);
    } while(next_permutation(p.begin(), p.end()));

    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}