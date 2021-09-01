#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    map<long long, long long> mp1, mp2;
    for(int i = 0;i < n;i++){
        long long l = (i + 1) + a[i], r = (i + 1) - a[i];
        mp1[l]++;
        mp2[r]++;
    }

    long long ans = 0;
    for(int i = 1;i <= n;i++){
        ans += mp1[i]*mp2[i];
    }

    cout << ans << endl;
}