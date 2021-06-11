#include "bits/stdc++.h"
using namespace std;

int same(vector<int> num){
    map<int, int> mp;
    int res = 0;
    for(int i = 0;i < num.size();i++){
        mp[num[i]] += 1;
        res = max(res, mp[num[i]]);
    }

    return res;
}

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<int>> p(h, vector<int>(w));
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            cin >> p[i][j];
        }
    }
    int ans = 0;
    for(int bit = 1;bit < (1 << h);bit++){
        vector<int> num;
        for(int i = 0;i < w;i++){
            int idx = -1;
            bool ok = true;
            for(int j = 0;j < h;j++){
                if ((bit & (1 << j)) == 0) continue;
                if (idx == -1) idx = p[j][i];
                else if (idx != p[j][i]) ok = false;
            }
            if (ok) num.push_back(idx);
        }

        int res = same(num);

        int cnt = 0;
        for(int i = 0;i < h;i++){
            if (bit & (1 << i)) cnt++; 
        }

        ans = max(ans, cnt * res);
    }

    cout << ans << endl;
}