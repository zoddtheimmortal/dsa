/** 
 immortalzodd
 07.08.2024 18:00:31
 slavicsExam
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
    string a,b; cin>>a>>b;

    int i=0,j=0,n=a.size(),m=b.size();
    while(i<n&&j<m){
    	if(a[i]==b[j]||a[i]=='?'){
    		a[i]=b[j];
    		i++; j++;
    	}
    	else i++;
    }
    if(j<m){
    	cout<<"NO"<<nL;
    	return;
    }

    while(i<n){
    	if(a[i]=='?') a[i]='a';
    	i++;
    }
    cout<<"YES"<<nL<<a<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}