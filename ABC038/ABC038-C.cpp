#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }

    long long cnt = 1;
    long long ans = 0;
    for(int i = 1;i < n;i++){
        if (a[i] <= a[i - 1]) {
            ans += cnt * (cnt +  1) / 2;
            cnt = 1;
        } else {
            cnt++;
        }
    }

    ans += cnt * (cnt + 1) / 2;
    cout << ans << endl;
}A