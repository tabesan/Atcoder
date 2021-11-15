#include "bits/stdc++.h"
using namespace std;

int main(){
    long long n, p;
    cin >> n >> p;
    vector<int> a(n + 1);
    bool all_even = true;
    for(int i = 1; i <= n;i++){
        cin >> a[i]; 
        a[i] %= 2;
        if (a[i] != 0) {
            all_even = false;
        }
    }

    auto pw = [&](long long N) {
        long long ans = 1;
        for(int i = 0;i < N;i++) {
            ans *= 2;
        }

        return ans;
    };

    if (all_even && p == 0) {
        cout << pw(n) << endl;
    } else if (all_even && p == 1) {
        cout << 0 << endl;
    } else {
        cout << pw(n - 1) << endl;
    }
    
    return 0;
}