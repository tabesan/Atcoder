#include "bits/stdc++.h"
using namespace std;

long long ceil_div(long long x, long long y) {
    return (x + y - 1) / y - !!((x + y - 1) & y < 0);
}

int main(){
    long long x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<long long> vec = {a, b, c};
    vector<long long> idx(3);
    iota(idx.begin(), idx.end(), 0);
    bool ok = false;
    
    do {
        {
            long long h1 = ceil_div(vec[idx[0]], x);
            long long h2 = ceil_div(vec[idx[1]], x);
            long long h3 = ceil_div(vec[idx[2]], x);
            if (h1 + h2 + h3 <= y) ok = true;

            long long h = y - h1;
            long long w1 = ceil_div(vec[idx[1]], h);
            long long w2 = ceil_div(vec[idx[2]], h);
            if (h > 0 && w1 + w2 <= x) ok = true;
        }

       {
           long long w1 = ceil_div(vec[idx[0]], y);
           long long w2 = ceil_div(vec[idx[1]], y);
           long long w3 = ceil_div(vec[idx[2]], y);
           if (w1 + w2 + w3 <= x) ok = true;

           long long w = x - w1;
           long long h1 = ceil_div(vec[idx[1]], w);
           long long h2 = ceil_div(vec[idx[2]], w);
            if (w > 0 && h1 + h2 <= y) ok = true;
       }

    } while(next_permutation(idx.begin(), idx.end()));

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}