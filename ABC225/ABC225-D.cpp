#include "bits/stdc++.h"
using namespace std;

struct List {
    int next;
    int prev;
};

int main(){
    int n, q;
    cin >> n >> q;
    vector<List> l(n + 1, {-1, -1});

    vector<deque<int>> ans(q);
    for(int i = 0;i < q;i++){
        int query;
        cin >> query;
        if (query == 1) {
            int x, y;
            cin >> x >> y;
            l[x].next = y;
            l[y].prev = x;
        } else if (query == 2) {
            int x, y;
            cin >> x >> y;
            l[x].next = -1;
            l[y].prev = -1;
        } else {
            int x;
            cin >> x;
            int pos = x;
            while(pos != -1){
                ans[i].push_front(pos);
                pos = l[pos].prev;
            }
            pos = l[x].next;
            while(pos != -1) {
                ans[i].push_back(pos);
                pos = l[pos].next;
            }
        }
    }    

    for(int i = 0;i < q;i++){
        if (ans[i].size() == 0) continue;
        cout << ans[i].size() << " ";
        while(!ans[i].empty()){
            cout << ans[i].front() << " ";
            ans[i].pop_front();
        }
        cout << endl;
    }

}B