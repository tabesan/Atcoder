#include "bits/stdc++.h"
using namespace std;

long long n, k, p;
long long a[50][50];
long long dp[50][50];

int counter(long long X) {
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if (a[i][j] == -1) dp[i][j] = X;
            if (a[i][j] != -1) dp[i][j] = a[i][j];
        }
    }

    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int cnt = 0;
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            if (dp[i][j] <= p) cnt++;
        }
    }

    return cnt;
}

long long binary(long long num) {
    long long l = 1, r = 5e9, mini = 5e9;
    for(int i = 0;i < 40;i++){
        long long mid = (l + r) / 2LL;
        int tmp = counter(mid);
        if (tmp <= num) {
            r = mid;
            mini = min(mini, mid);            
        } else {
            l = mid;
        }
    }
    return mini;
}

int main(){
    cin >> n >> p >> k;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> a[i][j];
        }
    }

    long long l = binary(k);
    long long r = binary(k - 1);
    if (r - l >= 2e9) cout << "Infinity" << endl;
    else cout << r - l << endl;
}