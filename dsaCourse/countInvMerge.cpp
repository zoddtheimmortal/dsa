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

int merge(vi &arr,int si,int mid,int ei){
	int ans=0;
	int i=si,j=mid,k=0;
	vi temp(ei-si+1,0);
	while(i<mid&&j<=ei){
		if(arr[i]>arr[j]){
			temp[k++]=arr[j++];
			ans+=mid-i;
		}else{
			temp[k++]=arr[i++];
		}
	}

	while(i<mid) temp[k++]=arr[i++];
	while(j<=ei) temp[k++]=arr[j++];

	k=0;
	fr(i,si,ei+1){
		arr[i]=temp[k++];
	}

	return ans;
}
	
int mergeCount(vi &arr,int si,int ei){
	if(si<ei){
		int mid=si+(ei-si)/2;
		int x=mergeCount(arr,si,mid);
		int y=mergeCount(arr,mid+1,ei);
		int z=merge(arr,si,mid+1,ei);
		return x+y+z;
	}
	return 0;
}

void solve(){
    ll n; cin>>n;
    vi arr(n,0); fr(i,0,n) cin>>arr[i];
    cout<<mergeCount(arr,0,n-1)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}
