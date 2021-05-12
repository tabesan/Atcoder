#include "bits/stdc++.h"
#include<sstream>
using namespace std;
typedef long long ll;
#define _USE_MATH_DEFINES
#include <math.h>
#define NIL = -1;
#define all(x) x.begin(),x.end()
const ll INF = 1e9;
const long long inf = 1e18;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;

class RMQ {
public:
    int size_ = 1;
    vector<long long> data;

    void init(int len) {
        while(size_ <= len) size_ *= 2;
        data.resize(size_ * 2, -1e18);
    }

    void update(int pos, long long num){
        pos += size_;
        data[pos] = num;
        while(pos >= 2) {
            pos >>= 1;
            data[pos] = max(data[pos * 2], data[pos * 2 + 1]);
        }
    }

    long long query_(int l, int r, int a, int b, int u){
        if (l <= a && b <= r) return data[u];
        if (r <= a || b <= l) return -1e18;
        long long res1 = query_(l, r, a, (a + b) >> 1, u * 2);
        long long res2 = query_(l, r, (a + b) >> 1, b, u * 2 + 1);
        return max(res1, res2);
    }

    long long query(int l, int r){
        return query_(l, r, 0, size_, 1);
    }
};

long long w, n;
long long l[510], r[510], v[510];
long long dp[510][10010];
RMQ q[510];

int main(){
    cin >> w >> n;
    for(int i = 1;i <= n;i++) {
        cin >> l[i] >> r[i] >> v[i];
    }

    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= w;j++) {
            dp[i][j] = -1e18;
            q[i].init(w + 2);
        }
    }

    dp[0][0] = 0;
    q[0].update(0, 0);

    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= w;j++) dp[i][j] = dp[i - 1][j];
        for(int j = 0;j <= w;j++) {
            int cl = max(0, j - (int)r[i]), cr = max(0, j - (int)l[i] + 1);
            if (cl == cr) continue;
            long long value = q[i - 1].query(cl, cr);
            if (value != -1e18) {
                dp[i][j] = max(dp[i][j], value + v[i]);
            }
        }
        for(int j = 0;j <= w;j++) {
            q[i].update(j, dp[i][j]);
        }
    }

    if (dp[n][w] == -1e18) cout << "-1" << endl;
    else cout << dp[n][w] << endl;
}