#include "bits/stdc++.h"
using namespace std;
const long long MOD = 1e9 + 7;

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

int main(){
    long long k, n;
    cin >> n >> k;

    vector<long long> ans(n + 1);
    ans[1] = n - k + 1;
    init();
    for(int i = 2;i <= n;i++){
        long long res1 = nCr(n - k + 1, i);
        long long res2 = nCr(k - 1, i - 1);
        ans[i] = res1 * res2 % MOD;
    }

    for(int i = 1;i <= k;i++){
        cout << ans[i] << endl;
    }
}