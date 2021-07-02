#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i = 0;i < n;i++){
        cin >> a[i] >> b[i];
    }

    int rowMax = max(*max_element(a.begin(), a.end()), k) + 1;
    int colMax = max(*max_element(b.begin(), b.end()), k) + 1;
    vector<vector<int>> sum(rowMax + 1, vector<int>(colMax + 1));
    for(int i = 0;i < n;i++){
        sum[a[i] + 1][b[i] + 1]++;
    }

    for(int i = 1;i <= rowMax;i++){
        for(int j = 1;j <= colMax;j++){
            sum[i][j] += sum[i - 1][j];
        }
    }

    for(int i = 1;i <= rowMax;i++){
        for(int j = 1;j <= colMax;j++){
            sum[i][j] += sum[i][j - 1];
        }
    }

    int ans = 0;
    for(int i = 0;i <= rowMax - k - 1;i++){
        for(int j = 0;j <= colMax - k - 1;j++){
            ans = max(ans, sum[i][j] + sum[i + k + 1][j + k + 1] - sum[i][j + k + 1] - sum[i + k + 1][j]);
        }
    }

    cout << ans << endl;
}