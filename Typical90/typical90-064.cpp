#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<long long> a(n + 1), b(n);
    vector<long long> l(q), r(q), v(q);
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }

    long long sum = 0;
    for(int i = 1;i <= n - 1;i++){
        b[i] = a[i + 1] - a[i];
        sum += abs(b[i]);
    }

    for(int i = 0;i < q;i++){
        cin >> l[i] >> r[i] >> v[i];
    }

    vector<long long> ans;
    for(int i = 0;i < q;i++){
        long long before = abs(b[l[i] - 1]) + abs(b[r[i]]);
        if (l[i] >= 2) b[l[i] - 1] += v[i];
        if (r[i] <= n - 1) b[r[i]] -= v[i];
        long long after = abs(b[l[i] - 1]) + abs(b[r[i]]);
        sum += (after - before);
        ans.push_back(sum);
    }

    for(auto a : ans){
        cout << a << endl;
    }
}