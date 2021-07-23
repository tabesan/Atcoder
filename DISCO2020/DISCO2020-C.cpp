#include "bits/stdc++.h"
using namespace std;

int h, w, k, num;
char s[310][310];
int ans[310][310];
int straw[310];

void func(int l, int r){
    vector<int> pos;
    for(int i = l;i <= r;i++){
        for(int j = 1; j <= w;j++){
            if (s[i][j] == '#') pos.push_back(j);
        }
    }
    sort(pos.begin(), pos.end());

    for(int i = 0;i < pos.size();i++){
        int v1 = 1, v2 = w;
        if (i >= 1) v1 = pos[i - 1] + 1;
        if (i < (int)pos.size() - 1) v2 = pos[i];

        num++;
        for(int j = l;j <= r;j++){
            for(int k = v1;k <= v2;k++){
                ans[j][k] = num;
            }
        }
    }
}

int main(){
    cin >> h >> w >> k;
    for(int i = 1;i <= h;i++){
        for(int j = 1;j <= w;j++){
            cin >> s[i][j];
            if (s[i][j] == '#'){
                straw[i]++;
            }
        }
    }

    vector<int> strawExist;
    for(int i = 1;i <= h;i++){
        if (straw[i] >= 1) strawExist.push_back(i);
    }

    for(int i = 0;i < strawExist.size();i++){
        int v1 = 1, v2 = h;
        if (i >= 1) v1 = strawExist[i - 1] + 1;
        if (i < (int)strawExist.size() - 1) v2 = strawExist[i];

        func(v1, v2);
    }

    for(int i = 1;i <= h;i++){
        for(int j = 1;j <= w;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}