/** 
 immortalzodd
 29.05.2024 15:10:18
 petyaAndStaircases
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
    ll n,m; cin>>n>>m;
    if(m==0){
    	cout<<"YES"<<nL;
    	return;
    }
    vi dirty(m,0); for(int&x:dirty) cin>>x;
    sort(all(dirty));
    bool first=(dirty[0]==1),last=(dirty[m-1]==n);
    bool consec=false;
    fr(i,2,m){
    	if(dirty[i]-dirty[i-1]==1&&dirty[i-1]-dirty[i-2]==1){
    		consec=true;
    		break;
    	}
    }
    cout<<(first||last||consec?"NO":"YES")<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}