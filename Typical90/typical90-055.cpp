#include "bits/stdc++.h"
using namespace std;

int main() {
    long long n, p, q;
    cin >> n >> p >> q;
    vector<long long> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
        a[i] %= p;
    }
    long long ans = 0;
    for(int i = 0;i < n - 4;i++){
        for(int j = i + 1;j < n - 3;j++){
            for(int k = j + 1;k < n - 2;k++){
                for(int l = k + 1; l < n - 1;l++){
                    for(int m = l + 1;m < n; m++){
                        long long res1 = a[i]*a[j] % p;
                        long long res2 = a[k]*a[l] % p;
                        long long res3 = res1 * res2 % p;
                        if (res3 * a[m] % p == q) {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}