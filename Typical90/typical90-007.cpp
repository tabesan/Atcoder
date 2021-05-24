#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, q;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    cin >> q;
    vector<long long> b(q);
    for(int i = 0;i < q;i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end());

    for(int i = 0;i < q;i++){
        auto itr = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        if (itr - 1 >= 0){
            cout << min(abs(b[i] - a[itr]), abs(b[i] - a[itr - 1])) << endl;;
        } else {
            cout << abs(b[i] - a[itr]) << endl;
        }
    }
}
