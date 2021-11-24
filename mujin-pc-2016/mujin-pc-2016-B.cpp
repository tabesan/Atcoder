#include "bits/stdc++.h"
using namespace std;

int main(){
    vector<double> d(3);
    cin >> d[0] >> d[1] >> d[2];
    sort(d.begin(), d.end());
    double pi = 3.14159265358979;
    double sum = d[0] + d[1] + d[2];
    double ans = pi*sum*sum;
    if (d[2] - (d[0] + d[1]) > 0) {
        double tmp = d[2] - (d[0] + d[1]);
        ans -= pi*tmp*tmp;
    }

    cout << setprecision(12) << ans << endl;
}