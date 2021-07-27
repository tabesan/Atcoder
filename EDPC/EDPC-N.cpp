#include "bits/stdc++.h"
using namespace std;

long long dp[410][410];
long long seen[410][410];
long long sum[410];
long long dfs(int l, int r){
    if (seen[l][r]) return dp[l][r];
    if (l == r) return 0;
    seen[l][r] = true;

    long long res = 1e18;
    for(int i = l;i < r;i++){
        res = min(res, dfs(l, i) + dfs(i + 1, r) + sum[r] - sum[l - 1]);
    }
    return dp[l][r] = res;

}
int main(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    long long ans = dfs(1, n);
    cout << ans << endl;
}