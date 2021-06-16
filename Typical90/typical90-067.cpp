#include "bits/stdc++.h"
using namespace std;

long long from8To10 (string n) {
    long long ans = 0, x = 1;
    for(int i = n.size() - 1;i >= 0;i--){
        ans += 1LL * (n[i] - '0') * x;
        x *= 8LL;
    }
    return ans;
}

string from10To9 (long long n) {
    if (n == 0){
        return "0";
    }

    string ans;
    while(n > 0){
        char c = ((n % 9) + '0');
        ans = c + ans;
        n /= 9;
    }
    return ans;
}

int main(){
    string n;
    int k;
    cin >> n >> k;

    for(int i = 0;i < k;i++){
        n = from10To9(from8To10(n));
        for(int j = 0;j < n.size();j++){
            if (n[j] == '8'){
                n[j] = '5';
            }
        }
    }

    cout << n << endl;
}