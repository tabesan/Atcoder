#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    long long sum = 0;
    long long p = 1;
    for(int i = 0;i < n;i++){
        sum += p * int(s[i] - 'a');
        p *= 2;
    }

    cout << sum << endl;
}