#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    int sum = 0;
    vector<pair<int, int>> ans;
    int sub = 2025 - n;
    for(int i = 1;i <= 9;i++){
        for(int j = 1;j <= 9;j++){
            if (i * j == sub){
                ans.push_back({i, j});
            }
        }
    }

    for(auto v : ans){
        cout << v.first << " x " << v.second << endl;
    }
}