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
    int h, w;
    cin >> h >> w;
    if (h == 1 || w == 1) cout << h * w << endl;
    else {
        cout << ((h + 1) / 2) * ((w + 1) / 2) << endl;
    }
    
}