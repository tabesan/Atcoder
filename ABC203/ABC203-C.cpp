#include "bits/stdc++.h"
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;
    vector<pair<long long, long long>> p;
    for(int i = 0;i < n;i++){
        long long a, b;
        cin >> a >> b;
        p.push_back({a, b});
    }
    sort(p.begin(), p.end());
    for(auto v : p){
        if (v.first > k){
            break;
        }
        k += v.second;
    }

    cout << k << endl;
}