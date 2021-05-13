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
    long long a, b, t = 1000000000000000000LL;
    cin >> a >> b;
    long long g = a / gcd(a, b);
    if (b <= t / g){
        cout << b * g << endl;
    } else {
        cout << "Large" << endl;
    }
}