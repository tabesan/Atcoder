#include "bits/stdc++.h"
using namespace std;

int main(){
    long long a, b, c;
    cin >> a >> b >> c;
    long long C = 1;
    for(int i = 0;i < b;i++){
        C *= c;
    }
    if (a < C){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}