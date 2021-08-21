#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    set<int> st;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        st.insert(a[i]);
    }

    for(int i = 0;i < n;i++){
        int num = a[i];
        for(long long j = 2;j*j <= a[i];j++){
            while(num % j == 0){
                num /= j;
                st.insert(j);
            }
            if(num != 1) st.insert(num);
        }
    }
    
    vector<bool> ng(m + 1, false);
    for(auto v : st){
        if (v == 1) continue;
        if (ng[v] == false){
            for(int j = v;j <= m;j += v){
                ng[j] = true;
            }
        }
    }

    vector<int> ans;
    for(int i = 1;i <= m;i++){
        if (ng[i] == false){
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for(auto v : ans){
        cout << v << endl;
    }
}