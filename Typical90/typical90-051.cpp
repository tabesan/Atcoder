#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, k;
    long long p;
    cin >> n >> k >> p;
    vector<long long> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    int harf = n / 2;
    vector<vector<long long>> c1(100), c2(100);
    for(int bit = 0;bit < (1 << harf);bit++){
        long long sum = 0, cnt = 0;
        for(int i = 0;i < harf;i++){
            if (bit & (1 << i)) {
                sum += a[i];
                cnt++;
            }
        }
        c1[cnt].push_back(sum);
    }    

    for(int bit = 0;bit < (1 << (n - harf));bit++){
        long long sum = 0, cnt = 0;
        for(int i = 0;i < n - harf;i++){
            if (bit & (1 << i)) {
                sum += a[harf + i];
                cnt++;
            }
        }
        c2[cnt].push_back(sum);
    }

    for(int i = 0;i <= n;i++){
        sort(c1[i].begin(), c1[i].end());
        sort(c2[i].begin(), c2[i].end());
    }

    long long ans = 0;
    for(int i = 0;i <= k;i++){
        for(int j = 0;j < (int)c1[i].size();j++){
            int pos = lower_bound(c2[k - i].begin(), c2[k - i].end(), p - c1[i][j] + 1) - c2[k - i].begin();
            ans += pos;
        }
    }

    cout << ans << endl;
}