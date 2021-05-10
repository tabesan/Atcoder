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
    vector<string> ans;
    for(int bit = 0;bit < (1 << n);bit++){
        int l = 0, r = 0;
        string s = "";
        bool ok = true;
        for(int i = 0;i < n;i++){
            if (r > l) {
                ok = false;
                break;
            }
            if (bit & (1 << i)) {
                s += "(";
                l++;
            } else {
                s += ")";
                r++;
            }
        }
        if (ok && l == r) {
            ans.push_back(s);
        }
    }

    sort(ans.begin(), ans.end());
    for(auto a : ans){
        cout << a << endl;
    }
}