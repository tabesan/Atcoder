#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    vector<long long> sum(n);
    sum[0] = a[0];
    for(int i = 1;i < n;i++){
        sum[i] = sum[i - 1] + a[i];
    }
    
    long long ans = 0;
    for(int i = 0;i < n - 1;i++){
        ans += (sum[n - 1] - sum[i]) - (n - i - 1)*a[i];
    }
    cout << ans << endl;
}