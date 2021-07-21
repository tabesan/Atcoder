#include "bits/stdc++.h"
using namespace std;
const long long MOD = 1e9 + 7;

int n, q;
long long X[60], Y[60], Z[60], W[60];
long long x[60], y[60], z[60], w[60]; 

long long func(){
    long long way = 0;
    for(int i = 0;i < (1 << n);i++){
        long long bit[15];
        for(int j = 0;j < n;j++){
            bit[j + 1] = (i / (1 << j)) % 2;
        }

        bool ok = true;
        for(int j = 0;j < q;j++){
            if (((bit[x[j]] | bit[y[j]]) | bit[z[j]]) != w[j]) ok = false;
        }
        if (ok) way++;
    }

    return way;
}  

int main(){
    cin >> n >> q;
    for(int i = 0;i < q;i++){
        cin >> X[i] >> Y[i] >> Z[i] >> W[i];
    }

    long long bitW;
    long long ans = 1;
    for(int i = 0;i < 60;i++){
        for(int j = 0;j < q;j++){
            x[j] = X[j], y[j] = Y[j], z[j] = Z[j];
            w[j] = (W[j] / (1LL << i)) % 2LL;
        }

        long long res = func();
        ans *= res;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}