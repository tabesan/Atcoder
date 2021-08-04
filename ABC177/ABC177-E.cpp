#include "bits/stdc++.h"
using namespace std;

 
long long gcd(long long a,long long b) {
    if (a < b) swap(a,b);
    if (b == 0) return a;
    
    return gcd(b,a%b);
}

long long num[1000010];
bool seen[1000010];
int main(){
    int n;
    cin >> n;

    vector<long long> a(n);
    int g;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        num[a[i]]++;
        if (i == 0){
            g = a[i];
        } else {
            g = gcd(g, a[i]);
        }
    }

    bool pairwise = true;
    for(int i = 2;i <= 1000000;i++){
        int sum = 0;
        for(int j = i;j <= 1000000;j += i){
            sum += num[j];
        }

        if (sum > 1){
            pairwise = false;
            break;
        }   
    }

    if (pairwise){
        cout << "pairwise coprime" << endl;
        return 0;
    } else if (g == 1){
        cout << "setwise coprime" << endl;
    } else {
        cout << "not coprime" << endl;
    }

}