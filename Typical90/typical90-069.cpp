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

int main(){
    long long n, k;
    cin >> n >> k;

    if (k == 1){
        cout << (n == 1 ? 1 : 0) << endl;
    } else if (n == 1){
        cout << k % MOD << endl;
    } else if (n == 2){
        cout << k * (k - 1) % MOD << endl;
    } else {
        cout << k * (k - 1) % MOD * modpow(k - 2, n - 2, MOD) % MOD << endl;
    }

    return 0;
}