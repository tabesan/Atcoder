#include "bits/stdc++.h"
using namespace std;

int t[101];
int dp[101][102010];
const int inf = 1000000000;
int main() {
    int n;
	cin >> n;
	for(int i = 0;i < n;i++){
        cin >> t[i];
    }
 
	for(int i = 0;i < n + 1;i++){
        for(int j = 0;j < 101010;j++){
            dp[i][j] = inf;
        }
    }
	dp[0][0] = 0;
	for(int i = 0;i < n;i++) {
        for(int j = 0;j < 101010;j++){
            if (dp[i][j] != inf) {
                dp[i + 1][j + t[i]] = min(dp[i + 1][j + t[i]], dp[i][j]);
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + t[i]);
	        }
        }
    }
 
	int ans = inf;
	for(int i = 0;i < 101010;i++){ 
        ans = min(ans, max(i, dp[n][i]));
    }
	cout << ans << endl;
}