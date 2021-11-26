#include "bits/stdc++.h"
using namespace std;

int main(){
    string s;
    int t;
    cin >> s >> t;
    int x = 0, y = 0;
    int hatena = 0;
    for(int i = 0;i < s.size();i++) {
        switch (s[i]){
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
            case 'U':
                y++;
                break;
            case 'D':
                y--;
                break;
            case '?':
                hatena++;
                break;
            default:
                break;
        }
    }   

    int ans;
    if (t == 1) {
        if (x >= 0) {
            x += hatena;
        } else {
            x -= hatena;
        }
    } else {
        for(int h = 0;h < hatena;h++) {
            if (x == 0 && y == 0) {
                x++;
            } else if (x != 0) {
                if (x > 0) x--;
                else x++;
            } else {
                if (y >= 0) {
                    y--;
                } else {
                    y++;
                }
            }
        }
    }

    cout << abs(x) + abs(y) << endl;
}