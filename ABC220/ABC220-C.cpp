#include "bits/stdc++.h"
using namespace std;

int main(){
    long long n, x;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        sum += a[i];
    }
    cin >> x;

    long long ans = x / sum;
    long long res = ans * sum;
    ans *= n;
    for(int i = 0;i < n;i++){
        if (res + a[i] > x) {
            ans++;
            break;
        } else {
            res += a[i];
            ans++;
        }
    }

    cout << ans << endl;
}