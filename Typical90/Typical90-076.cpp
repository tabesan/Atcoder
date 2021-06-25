#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        sum += a[i];
    }

    for(int i = 0;i < n;i++){
        a.push_back(a[i]);
    }

    if (sum / 10 <= 0){
        cout << "No" << endl;
        return 0;
    }
    int cnt = 0;
    int r = 0, l = 0;
    long long value = 0;
    bool ok = false;
    while(r < 2*n && l < 2*n){
        while((value < sum / 10) && l < 2*n) {
            value += a[l];
            l++;
            cnt++;
        }
        if (value == sum / 10 && cnt <= n) {
            ok = true;
            break;
        }
        if (l >= 2*n){
            break;
        }
        
        while((value > sum / 10) && r <= l){
            value -= a[r];
            r++;
            cnt--;
        }
        if (value == sum / 10 && cnt <= n){
            ok = true;
            break;
        }
    }

    if (ok){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}