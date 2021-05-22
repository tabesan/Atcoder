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
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    vector<int> cntB(100010, 0), cntC(100010, 0);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        cin >> b[i];
    }
    for(int i = 0;i < n;i++){
        cin >> c[i];
        c[i]--;
        cntC[c[i]]++;
    }

    for(int i = 0;i < n;i++){
        if (cntC[i] != 0){
            cntB[b[i]] += cntC[i];
        }
    }

    long long ans = 0;
    for(int i = 0;i < n;i++){
        ans += cntB[a[i]];
    }
    cout << ans << endl;
}