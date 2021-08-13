#include "bits/stdc++.h"
using namespace std;

long long num[200010];

int main(){
    memset(num, 0, sizeof(num));
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        num[a[i]]++;
    }

    long long sum = 0;
    for(int i = 1;i <= n;i++){
        sum += (num[i]*(num[i] - 1)) / 2;
    }

    long long tmp;
    for(int i = 1;i <= n;i++){
        tmp = sum - (num[a[i]]*(num[a[i]] - 1)) / 2;
        cout << tmp + ((num[a[i]] - 1)*(num[a[i]] - 2)) / 2 << endl;
    }
}