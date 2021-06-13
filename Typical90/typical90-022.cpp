#include "bits/stdc++.h"
using namespace std;
 
long long gcd(long long a,long long b) {
    if (a < b) swap(a,b);
    if (b == 0) return a;
    
    return gcd(b,a%b);
}

int main(){
    long long a, b, c;
    cin >> a >> b >> c;

    long long g = gcd(a, gcd(b, c));
    long long ans = (a / g - 1) + (b / g - 1) + (c / g - 1);
    cout << ans << endl;
}