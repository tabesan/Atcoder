#include "bits/stdc++.h"
using namespace std;

int main(){
    long long a, b, x;
    cin >> a >> b >> x;

    auto calc = [&](long long n) {
        return n == -1 ? 0 : (n/x + 1LL);
    };

    long long A = calc(a - 1);
    long long B = calc(b);
    cout << B - A << endl;
}