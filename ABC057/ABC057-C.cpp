#include "bits/stdc++.h"
using namespace std;
const long long INF = 1e9;

int main(){
    long long n;
    cin >> n;

    int ans = INF;
    for(long long i = 1;i*i <= n;i++){
        if (n % i == 0) {
            string res1 = to_string(i);
            string res2 = to_string(n / i);
            ans = min(ans, max(int(res1.size()), int(res2.size())));
        }
    }

    cout << ans << endl;
}