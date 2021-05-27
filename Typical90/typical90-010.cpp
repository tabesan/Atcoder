#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> sum(3, vector<int>(n + 1, 0));
    for(int i = 1;i <= n;i++){
        int c, p;
        cin >> c >> p;
        sum[c][i] = p;
    }

    for(int i = 1;i <= 2;i++){
        for(int j = 1;j <= n;j++){
            sum[i][j] += sum[i][j - 1];
        }
    }

    int q;
    cin >> q;
    for(int i = 0;i < q;i++){
        int l, r;
        cin >> l >> r;
        cout << (sum[1][r] - sum[1][l - 1]) << " " << (sum[2][r] - sum[2][l - 1]) << endl;
    }
}