#include "bits/stdc++.h"
#include<sstream>
using namespace std;
typedef long long ll;
#define _USE_MATH_DEFINES
#include <math.h>
#define NIL = -1;
#define all(x) x.begin(),x.end()
const ll INF = 1e9;
const long long inf = 1e18;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;

int main(){
    int N;
    double D, H;
    double ans = 0;
    cin >> N >> D >> H;
    for(int i = 0;i < N;i++){
        double d, h;
        cin >> d >> h;
        double height = h - d*((H - h)/(D - d));
        ans = max(ans, height);
    }

    cout << setprecision(9) << ans << endl;
    return 0;
}
