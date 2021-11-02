#include "bits/stdc++.h"
using namespace std;

struct robot {
    long long x;
    long long l;
    long long right;
};

int main(){
    int n;
    cin >> n;
    vector<long long> x(n), l(n);
    vector<robot> robo(n);
    for(int i = 0;i < n;i++){
        cin >> x[i] >> l[i];
        robo[i] = {x[i], l[i], x[i] + l[i]};
    }  

    sort(robo.begin(), robo.end(), [](robot &a, robot &b) {
        return a.right < b.right;
    });

    long long mx = -1e18;
    int cnt = 0;
    for(int i = 0;i < n;i++){
        if (robo[i].x - robo[i].l >= mx) {
            cnt++;
            mx = robo[i].right;
        }
    }

    cout << cnt << endl;

}