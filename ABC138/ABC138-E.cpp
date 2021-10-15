#include "bits/stdc++.h"
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;

    vector<vector<int>> idx(26);
    for(int i = 0;i < s.size();i++){
        idx[s[i] - 'a'].push_back(i + 1);
    }

    long long ans = 0, pos = 0;
    for(int i = 0;i < t.size();i++){
        int c = t[i] - 'a';
        if (idx[c].size() <= 0) {
            cout << -1 << endl;
            return 0;
        } else {
            auto itr = upper_bound(idx[c].begin(), idx[c].end(), pos);
            if (itr == idx[c].end()) {
                ans += int(s.size());
                itr = idx[c].begin();
            }

            pos = *itr;
        }
    }

    ans += pos;
    cout << ans << endl;
}