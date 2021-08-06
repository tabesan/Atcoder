#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<long long, long long>> input(n);
    int c, x;
    for(int i = 0;i < n;i++){
        cin >> x >> c;
        input[i] = {c, x};
    }
    sort(input.begin(), input.end());

    map<long long, bool> mp;
    vector<long long> L, R;
    L.push_back(0);
    R.push_back(0);
    for(auto v : input){
        if (!mp[v.first]){
            L.push_back(v.second);
            R.push_back(v.second);
            mp[v.first] = true;
        } else {
            int idx = L.size() - 1;
            L[idx] = min(L[idx], v.second);
            R[idx] = max(R[idx], v.second);
        }
    }

    int sz = L.size();
    vector<vector<long long>> dp(sz + 10, vector<long long>(2));
    dp[0][0] = 0;
    for(int i = 0;i < sz;++i){
        dp[i + 1][0] = min(dp[i][0] + abs(L[i] - R[i + 1]), dp[i][1] + abs(R[i] - R[i + 1]))
                       + abs(R[i + 1] - L[i + 1]);
        dp[i + 1][1] = min(dp[i][0] + abs(L[i] - L[i + 1]), dp[i][1] + abs(R[i] - L[i + 1]))
                       + abs(R[i + 1] - L[i + 1]);
    }

    long long ans = min(dp[sz][0] + abs(L[sz]), dp[sz][1] + abs(R[sz]));
    cout << ans << endl;
}