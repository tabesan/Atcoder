#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> x(n), y(n);
    for(int i = 0;i < n;i++){
        cin >> x[i] >> y[i];
    }

    set<pair<int, int>> st;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) {
            if (i == j) continue;
            long long X = x[i] - x[j];
            long long Y = y[i] - y[j];
            long long g = gcd(abs(X), abs(Y));
            st.insert({X/g, Y/g});
        }
    }

    cout << st.size() << endl;
}