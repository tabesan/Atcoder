#include "bits/stdc++.h"
using namespace std;

int main(){
    int a, b, w;
    cin >> a >> b >> w;

    int mini = 1e9, mx = 0;
    for(int i = 1;i <= 1000000;i++){
        if (a*i <= 1000*w && 1000*w <= b*i) {
            mini = min(mini, i);
            mx = max(mx, i);
        }
    }

    if (mx == 0) cout << "UNSATISFIABLE" << endl;
    else {
        cout << mini << " " << mx << endl;
    }
}