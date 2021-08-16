#include "bits/stdc++.h"
using namespace std;

string dir[16] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};

double Round(double num){
    num = floor(num * 100.0);
    num /= 100.0;
    int sub = num*10;
    double res;
    if (double(num*10 - sub) >= 0.5) {
        res = round(num*10 + 0.5) / 10.0;
    } else {
        res = round(num*10) / 10.0;
    }

    return res;
}

int check(double num){
    if (num >= 0.0 && num <= 0.2) return 0;
    else if (num >= 0.3 && num <= 1.5) return 1;
    else if (num >= 1.6 && num <= 3.3) return 2;
    else if (num >= 3.4 && num <= 5.4) return 3;
    else if (num >= 5.5 && num <= 7.9) return 4;
    else if (num >= 8.0 && num <= 10.7) return 5;
    else if (num >= 10.8 && num <= 13.8) return 6;
    else if (num >= 13.9 && num <= 17.1) return 7;
    else if (num >= 17.2 && num <= 20.7) return 8;
    else if (num >= 20.8 && num <= 24.4) return 9;
    else if (num >= 24.5 && num <= 28.4) return 10;
    else if (num >= 28.5 && num <= 32.6) return 11;
    else return 12;
}

int main(){
    double deg, dis;
    cin >> deg >> dis;
    deg /= 10.0;
    dis /= 60.0;
    double l = 11.25, r = 33.75;
    string Dir = "";
    for(int i = 1;i < 16;i++){
        if (deg >= l && deg < r){
            Dir = dir[i];
            break;
        }
        l += 22.5; r += 22.5;
    }
    if (Dir == "") Dir = "N";

    dis += 0.00001;
    auto p = Round(dis);
    int wind = check(p);
    if (wind == 0){
        cout << "C " << 0 << endl;
    } else {
        cout << Dir << " " << wind << endl;
    }

    return 0;
}