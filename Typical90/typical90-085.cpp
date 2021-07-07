#include "bits/stdc++.h"
using namespace std;

int main(){
    long long k;
    cin >> k;
    vector<long long> num;
    for(long long i = 1;i*i <= k;i++){
        if (k % i == 0LL){
            num.push_back(i);
            
            if (i != k / i){
                num.push_back(k / i);
            }
        }
    }

    int ans = 0;
    sort(num.begin(), num.end());
    for(int i = 0;i < num.size();i++){
        for(int j = i;j < num.size();j++){
            long long ab = num[i]*num[j];
            if ((k / num[i]) < num[j]) continue;
            if (k % (num[i] * num[j]) != 0LL) continue;
            long long c = k / ab;
            if (num[j] <= c) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}
