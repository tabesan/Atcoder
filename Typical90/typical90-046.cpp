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
    vector<long long> a(n), b(n), c(n);
    long long aCnt[50], bCnt[50], cCnt[50];
    for(int i = 0;i < 50;i++){
        aCnt[i] = 0;
        bCnt[i] = 0;
        cCnt[i] = 0;
    }
    
    for(int i = 0;i < n;i++){
        cin >> a[i];
        aCnt[a[i] % 46]++;
    }
    for(int i = 0;i < n;i++){
        cin >> b[i];
        bCnt[b[i] % 46]++;
    }
    for(int i = 0;i < n;i++){
        cin >> c[i];
        cCnt[c[i] % 46]++;
    }

    long long ans = 0;
    for(int i = 0;i <= 45;i++){
        for(int j = 0;j <= 45;j++){
            for(int k = 0;k <= 45;k++){
                if ((i + j + k) % 46 == 0) {
                    ans += aCnt[i] * bCnt[j] * cCnt[k];
                } 
            }
        }
    }

    cout << ans << endl;
}