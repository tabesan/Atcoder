#include "bits/stdc++.h"
using namespace std;

int main(){
    long long N, k;
    cin >> N >> k;
    long long n = N;
    if (n == 0){
        cout << 0 << endl;
        return 0;
    }
    vector<long long> num(100000, 0);
    vector<long long> ans;
    ans.push_back(n);
    num[n]++;
    int cnt = 0;
    int loopStart;
    while(cnt < k){
        string s = to_string(n);
        int sum = 0;
        for(int i = 0;i < s.size();i++){
            sum += int(s[i] - '0');
        }
        n = (n + sum) % 100000;
        
        if (num[n] != 0){
            loopStart = n;
            break;
        } else {
            ans.push_back(n);
            num[n]++;
            cnt++;
        }
    }

    if (cnt == k){
        cout << n << endl;
        return 0;
    }

    int outRange = 0;
    for(auto a : ans){
        if (a == loopStart){
            break;
        }
        outRange++;
    }
    k -= outRange;
    k %= (int(ans.size() - outRange));
    cout << ans[outRange + k] << endl;

}