#include "bits/stdc++.h"
using namespace std;

vector<pair<char, int>> runlength(string s) {
    int n = s.length();

    vector<pair<char, int>> res;
    char pre = s[0];
    int cnt = 1;
    for(int i = 1;i < n;i++){
        if (pre != s[i]) {
            res.push_back({pre, cnt});
            cnt = 1;
            pre = s[i];
        } else {
            cnt++;
        }
    }

    res.push_back({pre, cnt});
    return res;
}

int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    auto comp = runlength(s);
    int sz = comp.size();
    for(int i = 0;i < k;i++){
        if (sz >= 3) {
            sz -= 2;
        } else if (sz == 2) {
            sz = 1;
        }
    }

    cout << n - sz << endl;
}