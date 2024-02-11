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

bool checkAgg(vi pos,ll x,ll min){
	ll c=1,prev=0,next=1;
	while(next<pos.size()){
		if(pos[next]-pos[prev]>=min){
			c++;
			prev=next;
		}
		if(c==x) return true;
		next++;
	}
	return false;
}

void solve(){
    ll n,x; cin>>n>>x;
    vi pos(n,0); fr(i,0,n) cin>>pos[i];
    sort(all(pos));
    ll si=0,ei=pos[n-1]-pos[0];
    ll ans=0;
    while(si<=ei){
    	ll mid=si+(ei-si)/2;
    	if(checkAgg(pos,x,mid)){
    		si=mid+1;
    		ans=mid;
    	}
    	else{
    		ei=mid-1;
    	}
    }
    cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}