#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, d;
    cin >> n >> d;
    vector<long long> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    long long ans = 0;
    for(int bit = 0;bit < (1 << n);bit++){
        long long num = 0;
        int count = 0;
        for(int i = 0;i < n;i++){
            if (bit & (1 << i)) {
                num |= a[i];
                count++;
            }
        }

        int cnt = 0;
        for(int i = 0;i < d;i++){
            if ((num & (1LL << i)) == 0){
                cnt++;
            }
        }

        if (count % 2 == 0){
            ans += (1LL << cnt);
        } else {
            ans -= (1LL << cnt);
        }
    }

    cout << ans << endl;
    return 0;
}