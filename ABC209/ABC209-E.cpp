#include "bits/stdc++.h"
using namespace std;

int charToInt(char ch){
    if ('A' <= ch && ch <= 'Z') return ch - 'A';
    else return ch - 'a' + 26;
}

int strToInt(char a, char b, char c){
    return charToInt(a)*52*52 + charToInt(b)*52 + charToInt(c);
}

int main(){
    int n;
    cin >> n;
    const int mx = 52 * 52 * 52 + 1;
    vector<pair<int, int>> edge(n);
    vector<int> cnt(mx);
    vector<vector<int>> b(mx);
    for(int i = 0;i < n;i++){
        string s;
        cin >> s;
        int front = strToInt(s[0], s[1], s[2]);
        int back = strToInt(s[s.size() - 3], s[s.size() - 2], s[s.size() - 1]);
        edge[i] = make_pair(front, back);
        cnt[front]++;
        b[back].push_back(front);
    }

    vector<int> ans(mx, -1);
    queue<int> q;
    for(int i = 0;i < mx;i++){
        if(cnt[i] == 0){
            ans[i] = 0;
            q.push(i);
        }
    }

    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(auto v : b[p]) {
            if (ans[v] == -1) {
                cnt[v]--;
                if (ans[p] == 0){
                    ans[v] = 1;
                    q.push(v);
                } else if (cnt[v] == 0) {
                    ans[v] = 0;
                    q.push(v);
                }
            }
        }
    }

    for(int i = 0;i < n;i++){
        if (ans[edge[i].second] == -1) cout << "Draw" << endl;
        else if (ans[edge[i].second] == 0) cout << "Takahashi" << endl;
        else cout << "Aoki" << endl;
    }
}