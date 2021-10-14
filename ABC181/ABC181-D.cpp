#include "bits/stdc++.h"
using namespace std;

int main(){
    string s;
    cin >> s;

    map<char, int> mp;
    for(int i = 0;i < s.size();i++){
        mp[s[i]]++;
    }

    if (s.size() == 1) {
        if (s == "8"){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    } else if (s.size() == 2) {
        if (stoi(s) % 8 == 0) {
            cout << "Yes" << endl;
        } else {
            swap(s[0], s[1]);
            if (stoi(s) % 8 == 0) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
        return 0;
    } 

    for(int i = 0;i <= 9;i++){
        for(int j = 0;j <= 9;j++){
            for(int k = 0;k <= 9;k++){
                int tmp = i*100 + j*10 + k;
                if (tmp % 8 == 0) {
                    map<int, int> tmp;
                    char I = char(i + '0');
                    char J = char(j + '0');
                    char K = char(k + '0');
                    
                    tmp[I]++;
                    tmp[J]++;
                    tmp[K]++;

                    if (tmp[I] <= mp[I] && tmp[J] <= mp[J] && tmp[K] <= mp[K]){
                        cout << "Yes" << endl;
                        return 0;
                    }

                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
    
}