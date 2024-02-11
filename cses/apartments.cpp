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

ll search(vl arr,ll n, ll x, v(bool) &visited){
	ll si=0,ei=n-1;
	ll ans=-1;
	while(si<=ei){
		ll mid=si+(ei-si)/2;
		if(x>=arr[mid]){
			si=mid+1;
		}
		else{
			ei=mid-1;
			if(!visited[mid]){
				ans=mid;
			}
		}
	}

	return ans;
}

void solve(){
    ll n,m,k; cin>>n>>m>>k;
    vl arr(n,0); fr(i,0,n) cin>>arr[i];
    v(bool) visited(n,false);
    sort(all(arr));

    ll ans=0;

    while(m--){
    	ll x; cin>>x;
    	ll idx=search(arr,n,x,visited);
    	ll f=1,s=1;
    	rf(i,0,idx-1){
    		if(!visited[i]){
    			f=idx-i;
    			break;
    		}
    	}

    	fr(i,idx+1,n){
    		if(!visited[i]){
    			s=i-idx;
    			break;
    		}
    	}

    	cout<<x<<" "<<idx<<" f: "<<f<<" s: "<<s<<nL;
    	if(idx>=0 && idx<=n-1){
    		if(x>=arr[idx]-k && x<=arr[idx]+k){
    			visited[idx]=true;
    			ans++;
    		}
    		else if(idx-f>=0 &&x>=arr[idx-f]-k && x<=arr[idx-f]+k){
    			visited[idx-f]=true;
    			ans++;
    		}
    		else if(idx+s<=n-1 &&x>=arr[idx+s]-k && x<=arr[idx+s]+k){
    			visited[idx+s]=true;
    			ans++;
    		}
    	}
    	if(idx==-1){
    		if(x>=arr[0]-k && x<=arr[0]+k){
    			visited[0]=true;
    			ans++;
    		}
    	}

    }

    cout<<ans<<nL;
    fr(i,0,n) cout<<visited[i]<<" ";
    cout<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}