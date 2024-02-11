/**
 immortalZodd
 20.01.2024 11:11:10
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

pair<int,int> giveMax(vi start,vi end){
	vi arr(3);
	fr(i,0,3){
		arr[i]=end[i]-start[i];
	}
	sort(all(start)); sort(all(arr));
	return make_pair(start[2],arr[2]);
}

void solve(){
	freopen("hps.in","r",stdin);
	freopen("hps.out","w",stdout);
    ll n; cin>>n;
    vector<vi> arr(n+1,vi(3,0));
    fr(i,0,n){
    	char x; cin>>x;
    	arr[i+1][0]=arr[i][0];
    	arr[i+1][1]=arr[i][1];
    	arr[i+1][2]=arr[i][2];
    	if(x=='P'){
    		arr[i+1][0]++;
    	}
    	if(x=='H'){
    		arr[i+1][1]++;
    	}
    	if(x=='S'){
    		arr[i+1][2]++;
    	}
    }
    ll ans=0,temp=0;
    pair<int,int> comp;
    fr(i,0,n+1){
    	comp=giveMax(arr[i],arr[n]);
    	temp=comp.first+comp.second;
    	ans=max(temp,ans);
    }

    cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}