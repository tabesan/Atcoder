#include "bits/stdc++.h"
using namespace std;

int lis[300010];
int main(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }

    vector<int> lis1(n + 1), lis2(n + 1);
    int mx = -1;
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        int pos = lower_bound(lis, lis + cnt, a[i]) - lis;
        lis[pos] = a[i];
        lis1[i] = pos + 1;
        if (pos == cnt) cnt++;
    }

    cnt = 0;
    for(int i = n;i >= 1;i--){
        int pos = lower_bound(lis, lis + cnt, a[i]) - lis;
        lis[pos] = a[i];
        lis2[i] = pos + 1;
        if (pos == cnt) cnt++;
    }

    int ans = 0;
    for(int i = 1;i <= n;i++){
        ans = max(ans, lis1[i] + lis2[i] - 1);
    }

    cout << ans << endl;
}