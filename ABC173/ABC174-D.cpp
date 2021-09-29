#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int white = 0, red = 0;
    for(int i = 0;i < n;i++){
        if (s[i] == 'W') white++;
        else red++;
    }

    int ans = 0;
    int r = red;
    for(int i = 0;i < r;i++){
        if (s[i] == 'W') {
            if (red > 0) {
                ans++;
                red--;
            } else {
                ans++;
            }
        }
    }

    cout << ans << endl;
}