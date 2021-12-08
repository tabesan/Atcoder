#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        sum += a[i];
    }

    if (sum % n != 0) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    int target = sum / n;
    for(int i = 0;i < n - 1;i++){
        if (a[i] > target) {
            a[i + 1] += a[i] - target;
            ans++;
        } else if (a[i] < target) {
            a[i + 1] -= target - a[i];
            ans++;
        }
    }

    cout << ans << endl;
}