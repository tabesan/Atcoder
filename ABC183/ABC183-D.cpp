#include "bits/stdc++.h"
using namespace std;

long long sum[200010];
int main(){
    int n;
    long long w;
    cin >> n >> w;
    for(int i = 0;i < n;i++){
        int s, t;
        long long p;
        cin >> s >> t >> p;
        sum[s] += p;
        sum[t] -= p;
    }

    for(int i = 1;i <= 200000;i++) {
        sum[i] += sum[i - 1];
    }

    for(int i = 0;i <= 200000;i++){
        if (sum[i] > w){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;


}