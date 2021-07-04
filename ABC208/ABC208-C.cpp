#include "bits/stdc++.h"
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    vector<long long> b(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
        b[i] = a[i];
    }

    sort(a.begin(), a.end());
    map<long long, long long> mp;
    long long num = 0;
    if (k >= n){
        num = k / n;
        k %= n;
    }

    for(int i = 0;i < k;i++){
        mp[a[i]]++;
    }

    for(int i = 0;i < n;i++){
        if (mp[b[i]] == 0){
            cout << num << endl;
        } else {
            cout << num + 1 << endl;
        }
    }
}