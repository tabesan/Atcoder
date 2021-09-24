#include "bits/stdc++.h"
using namespace std;
const long long MOD = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }

    long long ans = 0;
    for(int i = 0;i < 60;i++){
        long long mask = 1LL << i;

        long long zero = 0, one = 0;
        for(int j = 0;j < n;j++){
            if (a[j] & mask) one++;
            else zero++;
        }

        long long tmp = (zero * one) % MOD;
        ans += ((mask % MOD)*tmp) % MOD;
        ans = (ans + MOD) % MOD;
    }

    cout << ans << endl;
}