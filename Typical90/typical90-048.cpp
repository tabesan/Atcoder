#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<long long> num;
    for(int i = 0;i < n;i++){
        long long a, b;
        cin >> a >> b;
        num.push_back(b);
        num.push_back(a - b);
    }
    sort(num.begin(), num.end(), greater<long long>());
    long long ans = 0;
    for(int i = 0;i < k;i++){
        ans += num[i];
    }

    cout << ans << endl;
}