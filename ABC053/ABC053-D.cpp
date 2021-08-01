#include "bits/stdc++.h"
using namespace std;

int num[100010];
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
        num[a[i]]++;
    }

    int ans = 0;
    for(int i = 1;i <= 100000;i++){
        if (num[i] > 1){
            ans += num[i] - 1;
        }
    }

    if (ans % 2 == 0){
        cout << n - ans << endl;
    } else {
        cout << n - (ans + 1) << endl;
    }
}