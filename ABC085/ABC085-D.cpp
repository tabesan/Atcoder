#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, h;
    cin >> n >> h;
    vector<long long> a(n), b(n);
    long long maxA = -1;
    for(int i = 0;i < n;i++) {
        cin >> a[i] >> b[i];
        maxA = max(maxA, a[i]);
    }

    sort(b.begin(), b.end(), greater<long long>());

    long long sum = 0;
    int ans = 0;
    for(int i = 0;i < n;i++) {
        if (b[i] > maxA) {
            sum += b[i];
            ans++;
        } else {
            break;
        }

        if (sum >= h) {
            break;
        }
    }

    if (sum >= h) {
        cout << ans << endl;
    } else {
        //ans += (h - sum)/maxA + ((h - sum)%maxA ? 1 : 0);
        ans += (h - sum + maxA - 1) / maxA;
        cout << ans << endl;
    }
}