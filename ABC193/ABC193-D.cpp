#include "bits/stdc++.h"
using namespace std;

long long score(vector<long long> &v) {
    long long res = 0;
    for(int i = 1;i <= 9;i++){
        long long num = i;
        for(int j = 0;j < v[i];j++){
            num *= 10;
        }
        res += num;
    }
    return res;
}

int main(){
    int k;
    string s, t;
    cin >> k >> s >> t;
    vector<long long> num(10, 0), numT(10, 0), numS(10, 0);
    for(int i = 0;i < 4;i++){
        numS[s[i] - '0']++;
        numT[t[i] - '0']++;
        num[s[i] - '0']++;
        num[t[i] - '0']++;
    }

    long long ans = 0;
    for(int i = 1;i <= 9;i++){
        for(int j = 1;j <= 9;j++){
            if (i == j){
                if (num[i] + 2 > k) continue;
                numS[i]++; numT[j]++;
                long long tmpS = score(numS);
                long long tmpT = score(numT);
                numS[i]--; numT[j]--;
                if (tmpS > tmpT) {
                    ans += (k - num[i])*(k - num[i] - 1);
                }
            } else {
                if (num[i] + 1 > k || num[j] + 1 > k) continue;
                numS[i]++; numT[j]++;
                long long tmpS = score(numS);
                long long tmpT = score(numT);
                numS[i]--; numT[j]--;
                if (tmpS > tmpT){
                    ans += (k - num[i])*(k - num[j]);
                }
            }
        }
    }
    long long r = (9*k - 8);
    cout << setprecision(12) << (double(ans) / r) / (r - 1) << endl;
}