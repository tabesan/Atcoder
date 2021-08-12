#include "bits/stdc++.h"
using namespace std;

long long dp[510][510];
int main(){
    int n, m, Q;
    cin >> n >> m >> Q;
    vector<int> l(m), r(m);    
    for(int i = 0;i < m;i++){
        cin >> l[i] >> r[i];
        dp[l[i]][r[i]]++;
    }

    for(int i = 1;i <= n;i++){
        for(int j = 2;j <= n;j++){
            dp[i][j] += dp[i][j - 1];
        }
    }

    int p, q;
    for(int i = 0;i < Q;i++){
        cin >> p >> q;
        int cnt = 0;
        for(int j = p;j <= q;j++){
            cnt += dp[j][q];
        }
        cout << cnt << endl;
    }
}