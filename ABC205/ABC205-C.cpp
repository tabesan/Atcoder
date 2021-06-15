#include "bits/stdc++.h"
using namespace std;

int main(){
    long long a, b, c;
    cin >> a >> b >> c;

    if (abs(a) == abs(b)){
        if (a == b){
            cout << "=" << endl;
            return 0;
        }
        
        if (a < 0){
            if (c % 2 == 0){
                cout << "=" << endl;
            } else {
                cout << "<" << endl;
            }
        } else {
            if (c % 2 == 0){
                cout << "=" << endl;
            } else {
                cout << ">" << endl;
            }
        }
        return 0;
    }

    if (a > b){
        if (a < 0 && b < 0){
            if (c % 2 == 0){
                cout << "<" << endl;
            } else {
                cout << ">" << endl;
            }
        } else if (b < 0){
            if (abs(a) < abs(b)){
                if (c % 2 == 0){
                    cout << "<" << endl;
                } else {
                    cout << ">" << endl;
                }
            } else {
                cout << ">" << endl;
            }
        } else {
            cout << ">" << endl;
        }
    } else if (a < b) {
        if (a < 0 && b < 0){
            if (c % 2 == 0){
                cout << ">" << endl;
            } else {
                cout << "<" << endl;
            }
        } else if (a < 0){
            if (abs(a) > abs(b)){
                if (c % 2 == 0){
                    cout << ">" << endl;
                } else {
                    cout << "<" << endl;
                }
            } else {
                cout << "<" << endl;
            }
        } else {
            cout << "<" << endl;
        }
    }
}