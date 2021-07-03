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

long long modDiv(long long a, long long b, long long m){
    return (a * modpow(b, m - 2, m)) % m;
}

long long sum1toC(long long C){
    long long v1 = C % MOD;
    long long v2 = (C + 1) % MOD;
    long long v = (v1 * v2) % MOD;
    return modDiv(v, 2, MOD);
}

unsigned long long power[30];
void initPow(){
    power[0] = 1;
    for(int i = 1;i <= 19;i++){
        power[i] = 10ULL * power[i - 1];
    }
}

int main(){
    unsigned long long l, r;
    cin >> l >> r;

    initPow();
    long long ans = 0;
    for(int i = 1;i <= 19;i++){
        unsigned long long res1 = max(l, power[i - 1]);
        unsigned long long res2 = min(r, power[i] - 1ULL);
        if (res1 > res2) continue;
        long long v = (sum1toC(res2) - sum1toC(res1 - 1) + MOD) % MOD;
        ans += 1LL * i * v;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}