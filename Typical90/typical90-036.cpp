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
    int n, q;
    cin >> n >> q;
    vector<long long> x(n), y(n);
    long long maxX = 0, minX = 1e18, maxY = 0, minY = 1e18;
    for(int i = 0;i < n;i++){
        long long X, Y;
        cin >> X >> Y;
        x[i] = X + Y;
        y[i] = X - Y;
        maxX = max(maxX, x[i]);
        minX = min(minX, x[i]);
        maxY = max(maxY, y[i]);
        minY = min(minY, y[i]);
    }

    for(int i = 0;i < q;i++){
        int p;
        cin >> p;
        p--;
        cout << max(max(abs(x[p] - maxX), abs(x[p] - minX)), max(abs(y[p] - maxY), abs(y[p] - minY))) << endl;;
    }
}