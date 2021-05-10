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
    long long l;
    cin >> n >> l >> k;
    vector<long long> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    long long ok = 1e9 + 1, ng = 0;
    while(ok - ng > 1){
        long long mid = (ok + ng) / 2;
        int cnt = 0;
        long long pre = 0;
        for(int i = 0;i < n;i++){
            if (a[i] - pre >= mid && l - a[i] >= mid){
                cnt++;
                pre = a[i];
            }
        }

        if (cnt < k) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << ng << endl;
}