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
    vector<long long> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    map<long long, int> mp;
    int l = 0, r = 0;
    int ans = 0, cnt = 0;
    int len = 0;
    while(r < n){
        while(cnt <= k && r < n){
            if (mp[a[r]] == 0) {
                if (cnt < k) cnt++;
                else {
                    break;
                }
            }
            mp[a[r]]++;
            r++; 
            len++;
        }

        ans = max(ans, len);
        while(cnt >= k && l < n){
            if (mp[a[l]] == 1){
                cnt--;
            }
            mp[a[l]]--;
            len--;
            l++;
        }
    }
    cout << ans << endl;
}