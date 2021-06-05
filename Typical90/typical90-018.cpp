#include "bits/stdc++.h"
using namespace std;

long double l, x, y, t;
long double PI = 3.14159265358979;

long double query(long double E){
    long double mx = 0;
    long double my = -(l/2.0)*sin(E/t*2.0*PI);
    long double mz = (l/2.0) - (l/2.0)*cos(E/t*2.0*PI); 
    long double dist = sqrt(x*x + (y - my)*(y - my));
    long double kaku = atan2(mz, dist);
    return kaku * 180.0/PI;
}
int main(){
    cin >> t >> l >> x >> y;
    int q;
    cin >> q;

    vector<double> ans;
    for(int i = 0;i < q;i++){
        long double e;
        cin >> e;
        ans.push_back(query(e));
    }

    for(auto a : ans){
        cout << setprecision(12) << a << endl;
    }
}