#include "bits/stdc++.h"
using namespace std;

int main(){
    int q;
    cin >> q;
    vector<int> l(q), r(q);
    for(int i = 0;i < q;i++) {
        cin >> l[i] >> r[i];
    }

    vector<bool> prime(100010, true);
    prime[1] = false;
    for(int i = 2;i <= 100000;i++) {
        if (prime[i]) {
            for(int j = i*2;j <= 100000;j += i) {
                prime[j] = false;
            }
        }
    }   

    vector<int> num(100010, 0);
    for(int i = 1;i <= 100000;i += 2) {
        if (prime[i] && prime[(i + 1)/2]) {
            num[i]++;
        }   
    }

    for(int i = 1;i <= 100000;i++){
        num[i] += num[i - 1];
    }

    vector<int> ans(q);
    for(int i = 0;i < q;i++) {
        ans[i] = num[r[i]] - num[l[i] - 1];
    }

    for(int i = 0;i < q;i++){
        cout << ans[i] << endl;
    }
}