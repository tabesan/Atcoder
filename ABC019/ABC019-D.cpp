#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    int longest = 0, node;
    for(int i = 2;i <= n;i++){
        int res;
        cout << "? " << 1 << " " << i << endl;
        cin >> res;
        if (res > longest){
            longest = res;
            node = i;
        }
    }

    longest = 0;
    int ans;
    for(int i = 1;i <= n;i++){
        int res;
        cout << "? " << node << " " << i << endl;
        cin >> res;
        if (res > longest){
            longest = res;
            ans = i;
        }
    }

    cout << "! " << longest << endl;
}