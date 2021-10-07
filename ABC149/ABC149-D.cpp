#include "bits/stdc++.h"
using namespace std;

long long dp[100010][3];
int main(){
    int n, k, r, s, p;
    cin >> n >> k >> r >> s >> p;
    string t;
    cin >> t;

    dp[1][0] = r;
    dp[1][1] = s;
    dp[1][2] = p;

    vector<int> ok(n + 1, 0);
    long long ans = 0;
    for(int i = 0;i < n;i++){
        if (i < k - 1) {
            if (t[i] == 'r') {
                ans += p;
            } else if (t[i] == 's') {
                ans += r;
            } else {
                ans += s;
            }
        } else {
            if (t[i - k] == t[i]) {
                if (ok[i - k] == 0) {
                    ok[i] = 1;
                } else {
                    if (t[i] == 'r') {
                        ans += p;
                    } else if (t[i] == 's') {
                        ans += r;
                    } else {
                        ans += s;
                    }
                }
            } else {
                if (t[i] == 'r') ans += p;
                else if (t[i] == 's') ans += r;
                else ans += s;
            }
        }
    }

    cout << ans << endl;
}