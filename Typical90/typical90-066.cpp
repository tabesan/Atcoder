#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<double> l(n), r(n);
    for(int i = 0;i < n;i++){
        cin >> l[i] >> r[i];
    }

    double ans = 0;
    for(int i = 0;i < n - 1;i++){
        for(int j = i + 1;j < n;j++){
            double cnt = 0;
            for(int k = l[i];k <= r[i];k++){
                for(int m = l[j];m <= r[j];m++){
                    if (k > m){
                        cnt++;
                    }
                }
            }
            ans += cnt / ((r[i] - l[i] + 1)*(r[j] - l[j] + 1));
        }
    }

    cout << setprecision(12) << ans << endl;
}