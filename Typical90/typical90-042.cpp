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
    int k;
    cin >> k;

    if (k % 9 == 0){
        vector<long long> ans(k + 1, 0);
        ans[0] = 1;
        for(int i = 1;i <= k;i++){
            for(int j = i - 1;j >= i - min(i, 9);j--){
                ans[i] += ans[j];
                ans[i] %= MOD;
            }
        }
        cout << ans[k] << endl;
    } else {
        cout << 0 << endl;
    }
}
