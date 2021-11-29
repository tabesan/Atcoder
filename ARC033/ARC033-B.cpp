#include <bits/stdc++.h>
using namespace std;

int main(){
    int Na, Nb;
    cin >> Na >> Nb;
    vector<int> a(Na), b(Nb);
    map<int, int> mpA, mpB;
    set<int> st;
    for(int i = 0;i < Na;i++) {
        cin >> a[i];
        mpA[a[i]]++;
        st.insert(a[i]);
    }

    for(int i = 0;i < Nb;i++) {
        cin >> b[i];
        mpB[b[i]];
        st.insert(b[i]);
    }

    double count = 0;
    for(auto v : mpA) {
        if (mpB.count(v.first) != 0) {
            count++;
        }
    }

    cout << setprecision(14) << count / double(st.size()) << endl;
}