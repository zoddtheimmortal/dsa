#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define v(x) vector<x>
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define rep(i,arr) for(auto i:arr)
#define nL "\n"

void solve(){
    string a,b,c;
    cin>>a>>b;
    int m=a.size(),n=b.size();
    int sum=0,carry=0;
    rf(i,0,n-1){
    	sum=((a[m-1]-'0')+(b[i]-'0')+carry)%10;
    	carry=((a[m-1]-'0')+(b[i]-'0')+carry)/10;
    	m--;
    	c+=(sum+'0');
    }
    rf(i,0,m-1){
    	c+=((a[i]-'0')+carry)%10+'0';
    	carry=((a[i]-'0')+carry)/10;
    }
    if(carry!=0) c+=(carry+'0');
    reverse(all(c));
    cout<<c<<nL;

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}