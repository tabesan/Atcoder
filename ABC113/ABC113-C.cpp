#include "bits/stdc++.h"
using namespace std;

struct py {
    int p;
    long long y;
    int city;
    string num;
};

string zeroume(string str) {
    while(str.size() < 6) {
        str = '0' + str;
    }

    return str;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> p(m);
    vector<long long> y(m);
    vector<py> v(m);
    for(int i = 0;i < m;i++){
        cin >> p[i] >> y[i];
        p[i]--;
        v[i] = {p[i], y[i], i, ""};
    }

    sort(v.begin(), v.end(), [](py &a, py &b) {
        return a.y < b.y;
    });

    vector<int> pref(n);
    for(int i = 0;i < m;i++){
        pref[v[i].p]++;
        string res = zeroume(to_string(v[i].p + 1));
        string res2 = zeroume(to_string(pref[v[i].p]));
        v[i].num = res + res2;
    }

    sort(v.begin(), v.end(), [](py &a, py &b) {
        return a.city < b.city;
    });

    for(int i = 0;i < m;i++){
        cout << v[i].num << endl;
    }
}