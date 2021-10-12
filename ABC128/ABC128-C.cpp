#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(m);
    for(int i = 0;i < m;i++){
        int k;
        cin >> k;
        for(int j = 0;j < k;j++){
            int S;
            cin >> S;
            S--;
            s[i].push_back(S);
        }
    }

    vector<int> p(m);
    for(int i = 0;i < m;i++){
        cin >> p[i];
    }

    int ans = 0;
    for(int bit = 0;bit < (1 << n);bit++){
        bool ok = true;
        for(int i = 0;i < m;i++){
            int sum = 0;
            for(int j = 0;j < s[i].size();j++){
                if (bit & (1 << s[i][j])) {
                    sum++;
                }
            }
            if (sum % 2 != p[i]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans++;           
        }
    }

    cout << ans << endl;
}