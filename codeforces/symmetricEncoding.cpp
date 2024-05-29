/** 
 immortalzodd
 24.05.2024 12:30:01
 symmetricEncoding
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

void solve(){
    ll n; cin>>n;
    string str; cin>>str;
    string key="";
    int count[26]={0};
    for(int i=0;i<n;i++){
    	if(!count[str[i]-'a']) key+=str[i];
    	count[str[i]-'a']=1;
    }
    sort(all(key));

    int map[26]={0},k=key.size();
    for(int i=0;i<k;i++){
    	map[key[i]-'a']=key[k-i-1];
    }

    for(char&c:str){
    	c=map[c-'a'];
    }
    cout<<str<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}