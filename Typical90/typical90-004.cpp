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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            cin >> a[i][j];
        }
    }

    vector<int> sumCol(h, 0), sumRow(w, 0);
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            sumCol[i] += a[i][j];
        }
    }

    for(int j = 0;j < w;j++){
        for(int i = 0;i < h;i++){
            sumRow[j] += a[i][j];
        }
    }

    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            cout << sumCol[i] + sumRow[j] - a[i][j] << " ";
        }
        cout << endl;
    }

    
}