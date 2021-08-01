#include "bits/stdc++.h"
using namespace std;

int main(){
    long long n, a, b;
    cin >> n >> a >> b;
    vector<long long> x(n);
    for(int i = 0;i < n;i++){
        cin >> x[i];
    }

    long long ans = 0;
    for(int i = 0;i < n - 1;i++){
        ans += min(b, a*(abs(x[i] - x[i + 1])));
    }

    cout << ans << endl;
}