#include "bits/stdc++.h"
using namespace std;

int main(){
    int k;
    cin >> k;
    if (k < 10) {
        cout << k << endl;
        return 0;
    }
    
    queue<long long> q;
    for(long long i = 1;i <= 9;i++) q.push(i);
    int cnt = 0;

    while(cnt < k) {
        long long p = q.front();
        q.pop();
        cnt++;
        if (cnt == k) {
            cout << p << endl;
            return 0;
        }

        if (p % 10 != 0) {
            q.push(p*10 + (p%10 - 1));
        }
        q.push(p*10 + p%10);
        if (p % 10 != 9) {
            q.push(p*10 + (p%10 + 1));
        }
    }
}