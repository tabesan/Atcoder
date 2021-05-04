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
    int n, k;
    cin >> n >> k;
    vector<int> num(n + 1, 0);
    for(int i = 2;i <= n;i++){
        if (num[i] >= 1) continue;
        for(int j = i;j <= n;j += i){
            num[j] += 1;
        }
    }

    int ans = 0;
    for(int i = 2;i <= n;i++){
        if (num[i] >= k) ans++;
    }

    cout << ans << endl;
    return 0;
}
