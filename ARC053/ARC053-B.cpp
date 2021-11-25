#include "bits/stdc++.h"
using namespace std;

int main(){
    string s;
    cin >> s;

    map<int, int> mp;
    for(int i = 0;i < s.size();i++) {
        mp[s[i] - 'a']++;
    }

    int odd = 0;
    for(int i = 0;i < 26;i++) {
        if (mp[i] % 2 != 0) {
            odd++;
        }
    }

    if (odd == 0) {
        cout << s.size() << endl;
    } else {
        cout << 2*(int(s.size() - odd) / (2*odd)) + 1 << endl;
    }
}