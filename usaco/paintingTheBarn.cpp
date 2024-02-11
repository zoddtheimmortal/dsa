/**
 immortalZodd
 21.01.2024 13:49:07
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

ll N=1000;

void solve(){
	freopen("paintbarn.in","r",stdin);
	freopen("paintbarn.out","w",stdout);
    ll n,k; cin>>n>>k;
    vector<vl> arr(N+1,vl(N+1,0));
    while(n--){
    	int x1,y1,x2,y2;
    	cin>>x1>>y1>>x2>>y2;
    	arr[x1][y1]++;
    	arr[x1][y2]--;
    	arr[x2][y1]--;
    	arr[x2][y2]++;
    }
    ll area=0;
    fr(i,0,N){
    	fr(j,0,N){
    		if(i>0) arr[i][j]+=arr[i-1][j];
    		if(j>0) arr[i][j]+=arr[i][j-1];
    		if(i>0 && j>0) arr[i][j]-=arr[i-1][j-1];
    		if(arr[i][j]==k) area++;
            // cout<<arr[i][j]<<" ";
    	}
        // cout<<nL;
    }
    cout<<area<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}