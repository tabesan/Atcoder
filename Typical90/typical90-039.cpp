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

int dp[100010];
void dfs(int pos, int pre, vector<vector<int>> &g) {
    dp[pos] = 1;
    for(auto nx : g[pos]){
        if (nx != pre) {
            dfs(nx, pos, g);
            dp[pos] += dp[nx];
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> a(n), b(n);
    for(int i = 0;i < n - 1;i++){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }

    dfs(0, -1, g);
    long long ans = 0;
    for(int i = 0;i < n - 1;i++){
        long long r = min(dp[a[i]], dp[b[i]]);
        ans += r * (n - r);
    }

    cout << ans << endl;
}