#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n + 1, 0);
    long long sum = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end(), greater<long long>());

    long long ans = 0;
    for(int i = 0;i < n;i++){
        long long dist = a[i] - a[i + 1];

        long long cnt = dist * (i + 1);
        if (cnt <= k){
            k -= cnt;
            ans += (dist*(a[i + 1] + 1 + a[i]) / 2) * (i + 1);
        } else {
            long long d = k / (i + 1);
            long long m = k % (i + 1);
            ans += (d*(a[i] + (a[i] - d + 1)) / 2)*(i + 1);
            ans += (a[i] - d) * m;
            k = 0;
        }
    }

    cout << ans << endl;
}