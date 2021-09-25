#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    long long even = 0, sum = 0;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        if (i % 2 != 0) {
            even += a[i];
        }
        sum += a[i];
    }

    vector<long long> ans(n);
    ans[0] = sum - 2*even;
    for(int i = 1;i < n;i++){
        ans[i] = 2LL*a[i - 1] - ans[i - 1];
    }

    for(auto v : ans){
        cout << v << " ";
    }
    cout << endl;
}