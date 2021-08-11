#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> ans(n + 1, 0);
    int dist;
    for(int i = 1;i < n;i++){
        for(int j = i + 1;j <= n;j++){
            dist = min(j - i, abs(i - x) + abs(j - y) + 1);
            ans[dist]++;
        }
    }

    for(int i = 1;i <= n - 1;i++){
        cout << ans[i] << endl;
    }
}