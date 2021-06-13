#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];

    long long sum = 0;
    for(int i = 0;i < n;i++){
        sum += abs(a[i] - b[i]);
    }

    if (sum <= k && ((sum % 2) == (k % 2))){
        cout << "Yes" << endl;
        return 0;
    } 
    cout << "No" << endl;
}