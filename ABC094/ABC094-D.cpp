#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    long long num = 1e9;
    for(int i = 0;i < n - 1;i++){
        if (abs(a[i] - a[n - 1]/2) <= abs(num - a[n - 1]/2)) {
            num = a[i];
        }
    }    

    cout << a[n - 1] << " " << num << endl;
}