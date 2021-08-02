#include "bits/stdc++.h"
using namespace std;

int main(){
    long long n;
    cin >> n;

    if (n % 2 == 1){
        cout << 0 << endl;
        return 0;
    }

    long long ans = n / 10;
    n /= 10;

    long long five = 5;
    while(five <= n){
        ans += n / five;
        five *= 5;
    }

    cout << ans << endl;
}