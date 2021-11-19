#include "bits/stdc++.h"
using namespace std;

int main(){
    string s;
    cin >> s;
    deque<char> q;
    for(int i = 0;i < s.size();i++) {
        q.push_back(s[i]);
    }

    long long ans = 0;
    while(q.size() > 1) {
        if (q.front() == q.back()) {
            q.pop_front();
            q.pop_back();
            continue;
        }

        if (q.front() == 'x') {
            ans++;
            q.pop_front();
        } else if (q.back() == 'x') {
            ans++;
            q.pop_back();
        } else {
            cout << -1 << endl;
            return 0;
        }
    }


    cout << ans << endl;
}