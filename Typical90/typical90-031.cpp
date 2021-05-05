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

int n;
int g[55][1510];
void Grundy() {
    for(int i = 0;i <= 50;i++){
        for(int j = 0;j <= 1500;j++){
            int mex[1510];
            for(int k = 0;k < 1510;k++){
                mex[k] = 0;
            }
            if (i >= 1) {
                mex[g[i - 1][j + i]] = 1;
            }
            if (j >= 2){
                for(int k = 1;k <= j/2;k++){
                    mex[g[i][j - k]] = 1;
                }
            }
            for(int k = 0;k < 1510;k++){
                if (mex[k] == 0) {
                    g[i][j] = k;
                    break;
                }
            }
        }
    }
}

int main(){
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];
    Grundy();
    int ans = 0;
    for(int i = 0;i < n;i++){
        ans ^= g[a[i]][b[i]];
    }

    if (ans != 0) cout << "First" << endl;
    else cout << "Second" << endl;

    return 0;
}