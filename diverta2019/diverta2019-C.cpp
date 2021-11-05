#include "bits/stdc++.h"
using namespace std;

int count_AB(string str) {
    int cnt = 0;
    for(int i = 0;i < str.size() - 1;i++){
        if (str[i] == 'A' && str[i + 1] == 'B') {
            cnt++;
        }
    }

    return cnt;
}

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    int sum = 0;
    int p1 = 0, p2 = 0, p3 = 0;
    for(int i = 0;i < n;i++){
        cin >> s[i];
        sum += count_AB(s[i]);
        int head = *s[i].begin();
        int tail = *(s[i].end() - 1);
        if (head == 'B' && tail == 'A') {
            p1++;
        } else if (head != 'B' && tail == 'A') {
            p2++;
        } else if (head == 'B' && tail != 'A') {
            p3++;
        }
    }

    if (p1 == 0) {
        sum += min(p2, p3);
    } else if (p1 != 0 && (p2 + p3) > 0) {
        sum += p1 + min(p2, p3);
    } else if (p1 != 0 && (p2 + p3) == 0) {
        sum += p1 - 1;
    }

    cout << sum << endl;
}