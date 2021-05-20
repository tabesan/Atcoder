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
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    int cnt = 0;
    vector<long long> ans;
    for(int i = 0;i < q;i++){
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1){
            x--;
            y--;
            x = (x - cnt + n) % n;
            y = (y - cnt + n) % n;
            long long tmp = a[x];
            a[x] = a[y];
            a[y] = tmp;
        } else if (t == 2){
            cnt = (cnt + 1) % n;
        } else {
            x--;
            ans.push_back(a[(x - cnt + n) % n]);           
        }
    }

    for(auto v : ans){
        cout << v << endl;
    }

    return 0;
}