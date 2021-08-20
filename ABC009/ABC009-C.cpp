#include "bits/stdc++.h"
using namespace std;

int check(vector<int> usable, vector<int> cnt) {
    int res = 0;
    for(int i = 0;i < 26;i++){
        res += max(0, usable[i] - cnt[i]);
    }
    return res;
}

int main(){
    int n, k;
    string s, ans = "";
    cin >> n >> k >> s;
    if (k == 0) {
        cout << s << endl;
        return 0;
    }

    vector<int> usable(26, 0), cnt(26, 0);
    for(int i = 0;i < n;i++){
        usable[s[i] - 'a']++;
        cnt[s[i] - 'a']++;
    }

    int limit = 0;
    for(int i = 0;i < n;i++){
        cnt[s[i] - 'a']--;
        if (limit == k){
            ans += s[i];
            continue;
        }

        for(int j = 0;j < 26;j++){
            if (usable[j] == 0) continue;
            if (j == s[i] - 'a') {
                ans += s[i];
                usable[j]--;
                break;
            }
            usable[j]--;
            if (limit + check(usable, cnt) + 1 <= k){
                limit++;
                ans += char(j + 'a');
                break;
            }
            usable[j]++;
        }
    }

    cout << ans << endl;

}