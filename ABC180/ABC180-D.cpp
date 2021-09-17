#include "bits/stdc++.h"
using namespace std;

int main(){
    int64_t x, y, a, b;
    cin >> x >> y >> a >> b;

    long long exp = 0;
    
    while((double)x*a <= 2e18 && x*a < y && x*a <= x + b) {
        x *= a;
        exp++;
    }

    exp += (y - x - 1) / b;
    cout << exp << endl;
}