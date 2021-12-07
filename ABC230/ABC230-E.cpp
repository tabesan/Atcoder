#include "bits/stdc++.h"
using namespace std;

int main(){
    long long n;
    cin >> n;

    long long res;
    for(long long i = 1;i <= n;i++) {
        if (i*i <= n) {
            res = i;
        } else {
            break;
        }
    }

    long long ans = 0;
    for(long long i = 1;i <= res;i++) {
        ans += ((n/i) - (n/(i + 1)))*i;
    }
    for(long long i = 1;i <= n/(res + 1);i++) {
        ans += n/i;
    }

    cout << ans << endl;
    return 0;
}