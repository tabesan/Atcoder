#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<long long> a(n + 1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    vector<long long> sum(n + 1);
    sum[0] = 0;
    for(int i = 1;i <= n;i++){
        sum[i] = sum[i - 1] + a[i];
    }

    long long ans = 0;
    for(int i = k;i <= n;i++){
        ans += sum[i] - sum[i - k];
    }

    cout << ans << endl;
}