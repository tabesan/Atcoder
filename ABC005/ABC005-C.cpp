#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n, m;
	cin >> t >> n;
	vector<int> a(n);
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	cin >> m;
	vector<int> b(m);
	for(int i = 0;i < m;i++){
		cin >> b[i];
	}
	int pos = 0, cnt = 0;
	for(int i = 0;i < n;i++){
		if (a[i] <= b[pos] && b[pos] <= a[i] + t){
			cnt++;
			pos++;
		}
	}
	
	if (cnt == m){
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}
	
	return 0;
}

	
	