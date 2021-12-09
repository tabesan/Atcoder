#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    long double a, b;
    cin >> n >> a >> b;
    vector<long long> s(n);
    long double sum = 0;
    bool same = false;
    long long pre = -1;
    set<long long > st;
    for(int i = 0;i < n;i++){
        cin >> s[i];
        sum += s[i];
        st.insert(s[i]);
    }
    
    if (st.size() == 1) {
        cout << -1 << endl;
        return 0;
    }
    

    sort(s.begin(), s.end());
    long double p = b / (s[n - 1] - s[0]);
    long double q = a - p*sum/double(n);

    cout << setprecision(14) << p << " " << q << endl;
}