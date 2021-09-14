#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    vector<pair<long long, int>> bc(m);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    for(int i = 0;i < m;i++){
        int b;
        long long c;
        cin >> b >> c;
        bc[i] = make_pair(c, b);
    }

    sort(a.begin(), a.end(), greater<long long>());
    sort(bc.begin(), bc.end(), greater<pair<long long, int>>());
    long long ans = 0;
    for(int i = 0;i < min(n, m);i++){
        if (a[i] < bc[i].first) {
            
        }
    }

    long long ans = 0;
    for(int i = 0;i < n;i++) ans += a[i];
    cout << ans << endl;
}