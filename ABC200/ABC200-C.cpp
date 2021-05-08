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
        a[i] %= 200;
    }

    vector<vector<int>> num(n + 1, vector<int>(201, 0));
    vector<int> cnt(201, 0);
    for(int i = 0;i < n;i++){
        num[i + 1][a[i]] = num[i][a[i]] + 1;
        cnt[a[i]]++;
        for(int j = 0;j <= 199;j++){
            if (j == a[i]) continue;
            num[i + 1][j] = num[i][j];
        }
    }

    long long ans = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= 199;j++){
            if ((a[i] - j) % 200 == 0){
                ans += cnt[j] - num[i + 1][j];
            } 
        }
    }

    cout << ans << endl;
}