/** 
 immortalzodd
 04.08.2024 00:16:45
 sort
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
    ll n,q; cin>>n>>q;
    string a,b; cin>>a>>b;
    vector<vi> pre1(n+1,vi(26,0));
    vector<vi> pre2(n+1,vi(26,0));

    for(int i=1;i<n+1;i++){
    	pre1[i][a[i-1]-'a']++;
    	pre2[i][b[i-1]-'a']++;

    	fr(k,0,26) pre1[i][k]+=pre1[i-1][k];
    	fr(k,0,26) pre2[i][k]+=pre2[i-1][k];
    }

    fr(i,0,q){
    	int l,r; cin>>l>>r;

    	int diff=0;
    	fr(i,0,26){
    		int v1=pre1[r][i]-pre1[l-1][i];
    		int v2=pre2[r][i]-pre2[l-1][i];
    		diff+=abs(v1-v2);
    	}
    	cout<<diff/2<<nL;
    }
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}