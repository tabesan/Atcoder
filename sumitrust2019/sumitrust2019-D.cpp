#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<int>> pos(10, vector<int>(n + 1, -1));
    for(int i = n - 1;i >= 0;i--){
        for(int j = 0;j < 9;j++){
            pos[j][i] = pos[j][i + 1];
            if (j == s[i] - '0') {
                pos[j][i] = i;
            }
        }
    }

    int ans = 0;
    for(int i = 0;i < 1000;i++){
        vector<int> pin(3);
        pin[0] = i / 100;
        pin[1] = i / 10 % 10;
        pin[2] = i % 10;
        
        int pos = 0;
        for(int j = 0;j < n;j++){
            if (s[j] - '0' == pin[pos]) {
                pos++;
            }

            if (pos == 3) {
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;
}