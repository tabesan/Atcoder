#include "bits/stdc++.h"
using namespace std;

int main(){
    long long n, C;
    cin >> n >> C;

    vector<tuple<int, long long, int>> tp;
    for(int i = 0;i < n;i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        tp.push_back(make_tuple(a, c, 1));
        tp.push_back(make_tuple(b + 1, c, -1));
    }

    sort(tp.begin(), tp.end());
    
    long long sum = 0, ans = 0;
    for(int i = 0;i < 2*n - 1;i++){
        if (get<2>(tp[i]) == 1){
            sum += get<1>(tp[i]);
        } else {
            sum -= get<1>(tp[i]);
        }
        ans += min(C, sum)*(get<0>(tp[i + 1]) - get<0>(tp[i]));
    }

    cout << ans << endl;
}