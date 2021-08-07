#include "bits/stdc++.h"
using namespace std;

int h, w, k;
string s[11];
int white[11];
int func(vector<int> b) {
    int res = 0;
    int pos = 0;

    while(pos < w){
        for(int i = 0;i < 11;i++){
            white[i] = 0;
        }

        int nx = pos;
        for(int i = pos;i < w;i++){
            bool ok = true;
            for(int j = 0;j < h;j++){
                if (s[j][i] == '1'){
                    white[b[j]]++;
                    if (white[b[j]] > k) ok = false;
                }
            }
            if (!ok) break;
            nx = max(nx, i + 1);
        }

        if (nx == pos) return 1e9;
        pos = nx;

        res++;
    }

    return res - 1;
}

int main(){
    cin >> h >> w >> k;
    for(int i = 0;i < h;i++){
        cin >> s[i];
    }

    int ans = 1e9;
    for(int bit = 0;bit < (1 << (h - 1));bit++){
        vector<int> block;
        int bl = 0, cnt = 0;
        for(int i = 0;i < h - 1;i++){
            block.push_back(bl);
            if (bit & (1 << i)){
                bl++;
                cnt++;
            }
        }
        block.push_back(bl);

        ans = min(ans, func(block) + cnt);
    }

    cout << ans << endl;
}