#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> d(n + 1, vector<int>(n + 1));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> d[i][j];
        }
    }

    vector<vector<long long>> sum(n + 1, vector<long long>(n + 1));
    sum[0][0] = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            sum[i][j] = sum[i][j - 1] + d[i][j];
        }

        for(int j = 1;j <= n;j++){
            sum[i][j] += sum[i - 1][j];
        }
    }

    vector<long long> mx(n*n + 1);
    int area;
    long long value;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            for(int k = i + 1;k <= n;k++){
               for(int l = j + 1;l <= n;l++){
                   area = (k - i) * (l - j);
                   value = sum[k][l] - sum[k][j] - sum[i][l] + sum[i][j];
                   mx[area] = max(mx[area], value);
                }
            }
        }
    }
    
    for(int i = 1;i < n*n;i++){
        mx[i + 1] = max(mx[i], mx[i + 1]);
    }
    
    int q, p;
    cin >> q;
    vector<long long> ans(q);
    for(int i = 0;i < q;i++){
        cin >> p;
        ans[i] = mx[p];
    }

    for(auto a : ans){
        cout << a << endl;
    }
}