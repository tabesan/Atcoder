#include "bits/stdc++.h"
using namespace std;

int main(){
    long long a, b, c, n;
    cin >> n >> a >> b >> c;
    long long ans = 1e9;
    for(int i = 0;i <= 9999;i++){
        for(int j = 0;j <= 9999 - i;j++){
            long long tmp = n - a*i - b*j;
            if (tmp % c == 0 && tmp >= 0){
                ans = min(ans, i + j + tmp/c);
            }
        }
    }

    cout << ans << endl;
}