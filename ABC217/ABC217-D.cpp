#include "bits/stdc++.h"
using namespace std;

int main(){
    long long l, q;
    cin >> l >> q;
    int cut = 0;
    vector<long long> ans;
    set<int> st;
    st.insert(0);
    st.insert(l);
    for(int i = 0;i < q;i++){
        long long c, x;
        cin >> c >> x;
        if (c == 1){
            st.insert(x);
            cut++;
        } else {
            auto itr = st.lower_bound(x);
            ans.push_back(*itr - *prev(itr));
        }
    }

    for(auto v : ans){
        cout << v << endl;
    }
}