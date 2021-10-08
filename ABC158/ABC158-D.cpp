#include "bits/stdc++.h"
using namespace std;

int main(){
    string s;
    cin >> s;
    deque<char> que;
    for(int i = 0;i < s.size();i++){
        que.push_back(s[i]);
    }
    int q;
    cin >> q;

    bool rev = false;
    for(int i = 0;i < q;i++){
        int t;
        cin >> t;
        if (t == 1) {
            rev = !rev;
        } else {
            int f;
            char c;
            cin >> f >> c;
            if (!rev) {
                if (f == 1) {
                    que.push_front(c);
                } else {
                    que.push_back(c);
                }
            } else {
                if (f == 1) {
                    que.push_back(c);
                } else {
                    que.push_front(c);
                }
            }
        }
    }

    if (!rev) {
        while(!que.empty()){
            cout << que.front();
            que.pop_front();
        }
    } else {
        while(!que.empty()) {
            cout << que.back();
            que.pop_back();
        }
    }
    cout << endl;
}