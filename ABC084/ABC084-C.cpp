#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> c(n - 1), s(n - 1), f(n - 1);
    for(int i = 0;i < n - 1;i++){
        cin >> c[i] >> s[i] >> f[i];
    }
    
    for(int i = 0;i < n - 1;i++){
        int ans = 0;
        for(int j = i;j < n - 1;j++){
            ans = max(ans, s[j]);

            int dist = ans - s[j];
            if (dist % f[j] > 0)  dist = f[j] - (dist % f[j]);
            else dist = 0;

            ans += dist + c[j];
        }
        cout << ans << endl;
    }
    cout << 0 << endl;
}