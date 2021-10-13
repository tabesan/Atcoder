#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<long long>> cnt(10, vector<long long>(10, 0));
    for(int i = 1;i <= n;i++){
        string str = to_string(i);
        cnt[str[0] - '0'][str[int(str.size() - 1)] - '0']++;
    }

    long long ans = 0;
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            ans += cnt[i][j] * cnt[j][i];
        }
    }

    cout << ans << endl;
}