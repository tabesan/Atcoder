#include "bits/stdc++.h"
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    long long l = 0, r = 1e18/k;
    while(r - l > 1) {
        long long mid = (l + r) / 2;
        long long sum = 0;
        for(int i = 0;i < n;i++){
            sum += min(mid, a[i]);
        }   

        if (mid*k > sum) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << l << endl;
}