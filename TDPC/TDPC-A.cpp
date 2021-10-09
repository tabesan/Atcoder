#include "bits/stdc++.h"
using namespace std;

bool ans[10010];
int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0;i < n;i++){
        cin >> p[i];
    }
    sort(p.begin(), p.end());

    memset(ans, false, sizeof(ans));
    ans[0] = true;
    for(int i = 0;i < n;i++){
        for(int j = 10000;j >= 0;j--){
            if (j - p[i] >= 0 && ans[j - p[i]]) {
                ans[j] = true;
            }
        }
    }

    int cnt = 0;
    for(int i = 1;i <= 10000;i++){
        if (ans[i]) cnt++;
    }

    cout << cnt + 1 << endl;
}