
#include "bits/stdc++.h"
using namespace std;
 
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

const long long md = 998244353;
int main(){
    int n;
    cin >> n;
    vector<long long> d(n);
    vector<long long> dp(n + 1, 0);
    long long mx = 0;
    for(int i = 0;i < n;i++){
        cin >> d[i];
        mx = max(mx, d[i]);
        dp[d[i]]++;
    }

    if (dp[0] != 1 || d[0] != 0) {
        cout << 0 << endl;
        return 0;
    }

    long long ans = 1;
    for(int i = 1;i <= mx;i++){
        ans *= modpow(dp[i - 1], dp[i], md);
        ans %= md;
    }
    
    cout << ans << endl;
}