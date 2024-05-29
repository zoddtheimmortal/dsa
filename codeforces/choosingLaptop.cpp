/** 
 immortalzodd
 24.05.2024 16:08:18
 choosingLaptop
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
    int n; cin>>n;
    vi cost(n),speed(n),ram(n),hdd(n),choice(n);
    fr(i,0,n){
    	cin>>speed[i]>>ram[i]>>hdd[i]>>cost[i];
    }
    fr(i,0,n){
    	int outdated=0;
    	fr(j,0,n){
    		if(speed[i]<speed[j]&&ram[i]<ram[j]&&hdd[i]<hdd[j]){
    			outdated=1;
    			break;
    		}
    	}
    	choice[i]=!outdated;
    }

    int ans=-1,minCost=INT_MAX;
    fr(i,0,n){
    	if(choice[i]&&cost[i]<minCost){
    		ans=i;
    		minCost=cost[i];
    	}
    }
    cout<<ans+1<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}