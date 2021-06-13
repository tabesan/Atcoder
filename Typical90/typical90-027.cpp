#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string, int> mp;
    vector<int> ans;
    for(int i = 0;i < n;i++){
        string s;
        cin >> s;
        if (mp[s] == 0){
            mp[s]++;
            ans.push_back(i + 1);
        }
    }

    for(auto a : ans){
        cout << a << endl;
    }
}