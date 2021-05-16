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
    string s;
    cin >> s;

    vector<vector<int>> num(n + 1, vector<int>(26));
    for(int i = 0;i < 26;i++) num[s.size()][i] = s.size();
    for(int i = s.size() - 1;i >= 0;i--){
        for(int j = 0;j < 26;j++){
            if (s[i] - 'a' == j) {
                num[i][j] = i;
            } else {
                num[i][j] = num[i + 1][j];
            }
        }
    }

    string ans = "";
    int cur = 0;
    for(int i = 1;i <= k;i++){
        for(int j = 0;j < 26;j++){
            int nx = num[cur][j];
            int mxLen = (int)(s.size() - nx - 1) + i;
            if (mxLen >= k) {
                ans += (char)(j + 'a');
                cur = nx + 1;
                break;
            }
        }
    }

    cout << ans << endl;
}