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
    string s;
    cin >> s;

    int ans = 0;
    for(int i = 0;i <= 9999;i++){
        vector<int> flag(10);
        int cur = i;
        for(int j = 0;j < 4;j++){
            flag[cur%10] = 1;
            cur /= 10;
        }
        bool ok = true;
        for(int j = 0;j <= 9;j++){
            if (s[j] == 'o' && !flag[j]){
                ok = false;
                break;
            }
            if (s[j] == 'x' && flag[j]){
                ok = false;
                break;
            }
        }
        if (ok) {
            ans++;
        }
    }

    cout << ans << endl;
}