#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    long long ans = 0;
    long long sum = 0, mx = 0, res = 0;
    for(int i = 0;i < n;i++){
        sum += a[i];
        mx = max(mx, sum);
        res = max(res, ans + mx);
        ans += sum;
    }

    cout << res << endl;
}