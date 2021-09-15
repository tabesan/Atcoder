#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<long long> h(n), w(m);
    for(int i = 0;i < n;i++){
        cin >> h[i];
    }
    for(int i = 0;i < m;i++){
        cin >> w[i];
    }

    sort(h.begin(), h.end());
    sort(w.begin(), w.end());

    vector<long long> front(n + 1), back(n + 1);
    for(int i = 0;i < n - 1;i += 2){
        front[i/2 + 1] = front[i / 2] + h[i + 1] - h[i];
    }
    for(int i = n - 2;i > 0;i -= 2){
        back[i/2] = back[i/2 + 1] + h[i + 1] - h[i];
    }

    long long ans = 1e18;
    for(int i = 0;i < m;i++){
        auto pos = lower_bound(h.begin(), h.end(), w[i]) - h.begin();
        if (pos % 2 != 0) pos ^= 1;
        ans = min(ans, front[pos / 2] + abs(w[i] - h[pos]) + back[pos / 2]);
    }

    cout << ans << endl;
}