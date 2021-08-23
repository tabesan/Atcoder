#include "bits/stdc++.h"
using namespace std;

int main(){
    int k;
    string s;
    cin >> s >> k;
    vector<int> num(int(s.size()));
    for(int i = 0;i < s.size();i++){
        num[i] = i;
    }

    vector<string> ans;
    string res;
    set<string> st;
    do {
        res = "";
        for(int i = 0;i < s.size();i++){
            res += s[num[i]];
        }
        st.insert(res);
    } while(next_permutation(num.begin(), num.end()));

    int cnt = 1;
    for(auto v : st){
        if (cnt == k){
            cout << v << endl;
            return 0;
        }
        cnt++;
    }


}
