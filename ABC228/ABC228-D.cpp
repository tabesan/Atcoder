#include "bits/stdc++.h"
using namespace std;

int main(){
    long long n = 1048576;
    int q;
    cin >> q;
    set<int> st;
    for(int i = 0;i < n;i++) {
        st.insert(i);
    }

    vector<long long> a(n, -1);
    vector<long long> ans;
    for(int i = 0;i < q;i++) {
        int t;
        long long x;
        cin >> t >> x;
        if (t == 1) {
            long long h = x % n;
            auto pos = st.lower_bound(h);
            
            if (pos == st.end()) {
                pos = st.lower_bound(0);
            } 

            a[*pos] = x;
            st.erase(*pos);
        } else {
            ans.push_back(a[x % n]);
        }
    }

    for(auto v : ans) {
        cout << v << endl;
    }
}