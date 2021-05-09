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
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    vector<vector<int>> ans(200, vector<int>(0));
    int cnt = min(n, 8);
    for(int bit = 0;bit < (1 << cnt);bit++){
        int sum = 0;
        vector<int> res;
        for(int j = 0;j < cnt;j++){
            if (bit & (1 << j)){
                res.push_back(j + 1);
                sum += a[j];
                sum %= 200;
            }
        }
        if (ans[sum].size() != 0){
            cout << "Yes" << endl;
            cout << ans[sum].size() << " ";
            for(auto v : ans[sum]){
                cout << v << " ";
            }
            cout << endl;
            cout << res.size() << " ";
            for(auto v : res){
                cout << v << " ";
            }
            cout << endl;
            return 0;
        } else {
            ans[sum] = res;
        }
    }

    cout << "No" << endl;
    return 0;
}