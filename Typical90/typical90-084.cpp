#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    long long sum = n*(n + 1LL)/2LL;
    int cnt = 0;
    char c;
    if (s[0] == 'o') {
        c = 'o';
    } else {
        c = 'x';
    }

    vector<long long> len;
    for(int i = 0;i < n;i++){
        if (s[i] == c){
            cnt++;
        } else {
            len.push_back(cnt);
            cnt = 1;
            c = (c == 'o' ? 'x' : 'o');
        }
    }
    len.push_back(cnt);

    for(auto l : len){
        sum -= l*(l + 1LL)/2LL;
    }

    cout << sum << endl;
}