#include "bits/stdc++.h"
using namespace std;
const long long MOD = 1e9 + 7;

long long modpow(long long a, long long b, long long m){
    long long ans = 1;
    while(b > 0){
        if (b % 2 == 1){
            ans *= a;
            ans %= m;
        }
        a *= a;
        a %= m;
        b /= 2;
    }
    return ans;
}

const int MAX = 1e5*2 + 1;
long long fac[MAX],finv[MAX],inv[MAX];
void init(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(int i=2;i<MAX;i++){
    fac[i]=fac[i-1]*i%MOD;
    inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
    finv[i]=finv[i-1]*inv[i]%MOD;
  }
}

long long nCr(int n,int k){
  if(n<k) return 0;
  if(n<0 || k<0) return 0;
  return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

long long combo(long long n, long long r) {
    long long res = 1;
    for(int i = 0;i < r;i++){
        res *= (n - i);
        res %= MOD;
        res *= inv[i + 1];
        res %= MOD;
    }

    return res;
}

int main(){
    long long n, a, b;
    cin >> n >> a >> b;

    long long all = modpow(2LL, n, MOD);

    init();
    long long A = combo(n, a);
    long long B = combo(n, b);
    long long ans = all - A - B - 1;
    ans = (ans + 2*MOD) % MOD;
    cout << ans << endl;
}