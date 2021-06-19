#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> x(n), y(n);
    for(int i = 0;i < n;i++){
        cin >> x[i] >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    long long mediX = x[n / 2];
    long long mediY = y[n / 2];

    long long ans = 0;
    for(int i = 0;i < n;i++){
        ans += abs(x[i] - mediX) + abs(y[i] - mediY);
    }

    cout << ans << endl;
}