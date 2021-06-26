#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long double> t(n), l(n), r(n);
    for(int i = 0;i < n;i++){
        cin >> t[i] >> l[i] >> r[i];
        if (t[i] == 2){
            r[i] -= 0.5;
        } else if (t[i] == 3){
            l[i] += 0.5;
        } else if (t[i] == 4){
            l[i] += 0.5;
            r[i] -= 0.5;
        }
    }
    
    long long ans = 0;
    for(int i = 0;i < n - 1;i++){
        for(int j = i + 1;j < n;j++){
            if ((l[i] <= l[j] && l[j] <= r[i]) || (l[i] <= r[j] && r[j] <= r[i])) {
                ans++;
            } else if ((l[j] <= l[i] && l[i] <= r[j]) || (l[j] <= r[i] && r[i] <= r[j])) {
                ans++;
            }
        }
    }

    cout << ans << endl;

}