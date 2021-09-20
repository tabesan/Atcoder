#include "bits/stdc++.h"
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long N = n;
    vector<long long> num;
    for(long long i = 2;i*i <= n;i++){
        if (n % i == 0)
        {
            num.push_back(i);
        }

        while(n % i == 0)
        {
            n /= i;
        }
    }

    if (n != 1) {
        num.push_back(n);
    }
    
    int cnt = 0;
    for(int i = 0;i < num.size();i++){
        for(long long j = num[i];j <= 1e12;j *= num[i]) {
            if (N % j == 0){
                N /= j;
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}