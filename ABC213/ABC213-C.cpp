#include "bits/stdc++.h"
using namespace std;

int main(){
    int h,w,n;
    cin >> h >> w >> n;
    vector<int> a(n), b(n), A(n), B(n);
    for(int i = 0;i < n;i++){
        cin >> a[i] >> b[i];
        A[i] = a[i];
        B[i] = b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    map<int, int> mpA, mpB;
    int num = 1;
    for(int i = 0;i < n;i++){
        if (mpA[a[i]] == 0) {
            mpA[a[i]] = num;
            num++;
        }
    }

    num = 1;
    for(int i = 0;i < n;i++){
        if (mpB[b[i]] == 0) {
            mpB[b[i]] = num;
            num++;
        }
    }
    for(int i = 0;i < n;i++){
        cout << mpA[A[i]] << " " << mpB[B[i]] << endl;
    }
}