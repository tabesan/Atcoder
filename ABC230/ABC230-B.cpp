#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string t = "oxxoxxoxxoxxoxxoxxoxx";

    for(int i = 0;i < t.size() - s.size();i++) {
        string tmp = t.substr(i, s.size());
        if (tmp == s) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}