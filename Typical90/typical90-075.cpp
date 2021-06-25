#include "bits/stdc++.h"
using namespace std;

vector<pair<long long, long long>> prime_fact(long long x){
    vector<pair<long long, long long>> res;
    for(long long i = 2;i*i <= x;i++){
        if (x % i == 0){
            long long cnt = 0;
            while(x % i == 0){
                cnt++;
                x /= i;
            }
            res.push_back({i, cnt});
        }
    }
    if (x != 1){
        res.push_back({x, 1});
    }
    return res;
}

int main(){
    long long n;
    cin >> n;
    auto res = prime_fact(n);

    long long cnt = 0;
    for(auto v : res){
        cnt += v.second;
    }

    long long devide = 1;
    long long ans = 0;
    while(devide < cnt){
        devide *= 2;
        ans++;
    }

    cout << ans << endl;
}