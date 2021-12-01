#include "bits/stdc++.h"
using namespace std;

int main(){
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a), q(b), r(c);
    for(int i = 0;i < a;i++){
        cin >> p[i];
    }
    for(int i = 0;i < b;i++){
        cin >> q[i];
    }
    for(int i = 0;i < c;i++){
        cin >> r[i];
    }

    sort(p.begin(), p.end(), greater<int>());
    sort(q.begin(), q.end(), greater<int>());
    sort(r.begin(), r.end(), greater<int>());

    priority_queue<int, vector<int>> que;
    for(int i = 0;i < min(x, a);i++){
        que.push(p[i]);
    }
    for(int i = 0;i < min(y, b);i++){
        que.push(q[i]);
    }
    for(int i = 0;i < min(c, x + y);i++){
        que.push(r[i]);
    }

    long long ans = 0;
    for(int i = 0;i < x + y;i++){
        ans += que.top();
        que.pop();
    }

    cout << ans << endl;
}