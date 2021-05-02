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


bool check(int num, int N, vector<vector<long long>> &a){
    set<int> st;
    for(int i = 0;i < N;i++){
        int bit = 0;
        for(int j = 0;j < 5;j++){
            if (a[i][j] >= num) {
                    bit |= 1 << j;
            }
        }
        st.insert(bit);
    }

    for(auto s1 : st){
        for(auto s2 : st){
            for(auto s3 : st){
                if ((s1 | s2 | s3) == 31){
                    return true;
                }
            }
        }
    }

    return false;
}

int main(){
    int n;
    cin >> n;
    vector<vector<long long>> a(n, vector<long long>(5));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 5;j++){
            cin >> a[i][j];
        }
    }

    int ok = 0, ng = 1e9 + 1;
    while(ng - ok > 1){
        int mid = (ok + ng) / 2;
        if (check(mid, n, a)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << ok << endl;
}