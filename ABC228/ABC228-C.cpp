#include "bits/stdc++.h"
using namespace std;

int main(){
    long long k, n;
    cin >> n >> k;
    vector<pair<long long, int>> sum(n);
    for(int i = 0;i < n;i++) {
        long long p1, p2, p3;
        cin >> p1 >> p2 >> p3;
        sum[i].first = p1 + p2 + p3;
        sum[i].second = i;
    }

    sort(sum.begin(), sum.end(), greater<pair<long long, int>>());

    vector<bool> ans(n, false);
    for(int i = 0;i < k;i++) {
        ans[sum[i].second] = true;
    }

    long long threshold = sum[k - 1].first;

    for(int i = k;i < n;i++) {
        if (sum[i].first + 300 >= threshold) {
            ans[sum[i].second] = true;
        }
    }

    for(int i = 0;i < n;i++) {
        if (ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}