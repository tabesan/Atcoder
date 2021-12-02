#include "bits/stdc++.h"
using namespace std;

int main(){
    long long s;
    cin >> s;

    long long M = 1e9;

    long long x3 = (M - (s % M)) % M;
    long long y3 = (s + x3) / M;
    
    printf("0 0 1000000000 1 %lld %lld\n", x3, y3);

}