#include "bits/stdc++.h"
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }

    vector<int> order(n + 1, 0);
    vector<int> loop;

    int pos = 1;
    int sz, start;
    while(!order[pos]) {
        order[pos] = loop.size();
        loop.push_back(pos);
        pos = a[pos];
    }
    sz = loop.size() - order[pos];
    start = order[pos];

    if (k < start){
        cout << loop[k] << endl;
    } else {
        k -= start;
        k %= sz;
        cout << loop[start + k] << endl;
    }
}