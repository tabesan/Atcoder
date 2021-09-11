#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    map<pair<int, int>, int> mp;
    for(int i = 0;i < n;i++){
        cin >> p[i].first >> p[i].second;
        mp[{p[i].first, p[i].second}]++;
    }
    sort(p.begin(), p.end());

    int ans = 0;
    for(int i = 0;i < n;i++){
        mp[{p[i].first, p[i].second}]--;
        for(int j = i + 1;j < n;j++){
            mp[{p[j].first, p[j].second}]--;
            if (mp[{p[i].first, p[j].second}] > 0 && mp[{p[j].first, p[i].second}] > 0) ans++;
            mp[{p[j].first, p[j].second}]++;
        }
        mp[{p[i].first, p[i].second}]++;
    }
    cout << ans / 2 << endl;
}