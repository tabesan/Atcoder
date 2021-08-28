#include "bits/stdc++.h"
using namespace std;

long long gcd(long long a,long long b) {
    if (a < b) swap(a,b);
    if (b == 0) return a;
    
    return gcd(b,a%b);
}
 
int main(){
    long long a, b;
    cin >> a >> b;

    long long g = gcd(a, b);
    map<long long, int> mp;
    for(long long i = 2;i*i <= g;i++){
        while(g % i == 0){
            g /= i;
            mp[i]++;
        }
    }
    
    if (g != 1){
        mp[g]++;
    }

    cout << mp.size() + 1 << endl;
}