#include "bits/stdc++.h"
using namespace std;

int main(){
    int k, n;
    cin >> n >> k;
    vector<double> num(n);
    for(int i = 0;i < n;i++){
        double p;
        cin >> p;
        num[i] = (p*(1.0 + p)) / 2.0;
        num[i] /= p;
    }
    
    int pos = 0;
    double sum = 0, ans = 0;
    for(int i = 0;i < n;i++){
        if (i < k - 1) {
            sum += num[i];
        } else {
            sum += num[i];
            ans = max(ans, sum);
            sum -= num[pos];
            pos++;
        }
    }
    cout << setprecision(14) << ans << endl;
}