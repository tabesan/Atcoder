#include "bits/stdc++.h"
using namespace std;

long long dp[100010];
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    for(int i = 1;i <= k;i++){
        int cnt = 0;
        bool win = false;
        for(int j = 0;j < n;j++){
            if (i - a[j] >= 0){
                cnt++;
                if (dp[i - a[j]] == 0) {
                    win = true;
                    break;
                }
            }
        }
        if (cnt == 0) dp[i] = 0;
        else if (win) dp[i] = 1;
        else dp[i] = 0;
    }

    if (dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;
}