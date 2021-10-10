#include "bits/stdc++.h"
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    int l = 0, r = 0;
    long long sum = 0, ans = 0;
    while(l < n) {
        while(sum < k && r < n){ 
            sum += a[r];
            r++;
        }

        if (sum >= k) {
            ans += n - r + 1;
        }

        sum -= a[l];
        l++;
    }

    cout << ans << endl;
}