#include "bits/stdc++.h"
using namespace std;

bool seen[3010][3010];
long long dp[3010][3010];
long long a[3010];

long long dfs(int l, int r){
    if (seen[l][r]) return dp[l][r];
    seen[l][r] = true;
    if (l == r) return dp[l][r] = a[l];
    return dp[l][r] = max(a[l] - dfs(l + 1, r), a[r] - dfs(l, r - 1));
}

int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }

    long long ans = dfs(0, n - 1);
    cout << ans << endl;
}