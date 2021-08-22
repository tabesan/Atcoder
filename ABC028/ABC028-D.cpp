#include "bits/stdc++.h"
using namespace std;

int main(){
    long double n, k;
    cin >> n >> k;
    long double all = n * n * n;
    long double sum = (n - k)*(k - 1)*6.0 + (n - 1)*3 + 1;
    
    cout << setprecision(14) << sum / all << endl;
}