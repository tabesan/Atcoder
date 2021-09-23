#include "bits/stdc++.h"
using namespace std;
const long long mod = 1e9 + 7;
#define MAX 3000000

long long fac[3000000],finv[3000000],inv[3000000];
 
void cominit(){
    fac[0] = 1;
    fac[1] = 1;
    finv[0] = 1;
    finv[1] = 1;
    inv[1] = 1;
    for (int i = 2;i < MAX;i++){
        fac[i] = fac[i-1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i-1] * inv[i] % mod;
    }
}
 
long long com(int n,int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
}

int main(){
    long long x, y;
    cin >> x >> y;

    cominit();
    for(long long a = 0;a <= x;a++){
        long long b = x - a;
        if (b % 2 != 0) continue;
        b /= 2;

        if (2*a + b == y) {
            cout << com(a + b, a) << endl;
            return 0;
        }
    }
    
    cout << 0 << endl;
}