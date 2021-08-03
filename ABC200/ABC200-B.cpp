#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/number.hpp>
using namespace boost::multiprecision;

int a,b;
#define For(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) For(i,0,n)
#define F first
#define S second
#define psb push_back
#define mkp make_pair
#define All(x) x.begin(),x.end()
#define nxp next_permutation
#define sep setprecision
#define tpf typedef
tpf double db;
tpf long long ll;
tpf vector<int> vi;
tpf vector<ll> vll;
tpf vector<string> vs;
tpf pair<int,int> pii;
tpf pair<ll,ll> pll;
tpf vector<pii> vpii;
tpf vector<vi> vvi;
const int mod = 1000000007;
const ll INF=1e17;
const int di[]={-1,0,1,0};
const int dj[]={0,-1,0,1};
ll gcd(ll x,ll y){
return y? gcd(y,x%y):x;
}
ll ncr(ll n,ll r){
  ll x=1,y=1;
  rep(i,r){x*=(n-i);y*=(i+1);}
  return x/y;
}
template<class T> inline bool chmin(T& a, T b){
  if(a>b){a=b;return true;}
  return false;
}
template<class T> inline bool chmax(T& a, T b){
  if(a<b){a=b;return true;}
  return false;
}

int main(){
  ll n,k;cin>>n>>k;
  rep(i,k){
    if(n%200==0)n/=200;
    else {
      string s=to_string(n);
      s+="200";
      n=stoll(s);
    }
  }
cout<<n;
return 0;
}
