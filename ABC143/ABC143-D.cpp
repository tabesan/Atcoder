#include "bits/stdc++.h"
using namespace std;

int cnt[2010];
int main(){
    int n;
    cin >> n;
    vector<int> l(n);
    for(int i = 0;i < n;i++){
        cin >> l[i];
        cnt[l[i]]++;
    }

    for(int i = 1;i <= 2000;i++){
        cnt[i] += cnt[i - 1];
    }
    
    long long ans = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if (i != j) {
                int mini = max(l[i] - l[j], l[j] - l[i]);
                int maxi = l[i] + l[j];

                int count = 0;
                if (maxi - 1 >= 0) count = cnt[maxi - 1];
                count -= cnt[mini];

                if (mini < l[i] && l[i] < maxi) count--;
                if (mini < l[j] && l[j] < maxi) count--;

                ans += count;
            }
        }
    }

    cout << ans / 6 << endl;
}