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

int naiveSoln(vi arr,int n){
	ll ans=0;
     fr(i,0,n){
     	fr(j,i+1,n){
     		if(arr[i]>arr[j] && i<j) ans++;
     	}
     }
     return ans;
}

ll merge(vi arr,int si,int mid,int ei){
	int i=si,j=mid,k=0;
	vi temp(ei-si+1,0);
	ll count=0;
	while(i<mid && j<=ei){
		if(arr[i]<=arr[j]) temp[k++]=arr[i++];
		else{
			count+=mid-i;
			temp[k++]=arr[j++];
		}
	}
	while(i<=mid) temp[k++]=arr[i++];
	while(j<=ei) temp[k++]=arr[j++];

	k=0;
	fr(i,si,ei+1){
		arr[i]=temp[k++];
	}
	return count;
}

ll mergeSort(vi arr,int si,int ei){
	ll count=0;
	if(si<ei){
		ll mid=si+(ei-si)/2;
		ll countLeft=mergeSort(arr,si,mid);
		ll countRight=mergeSort(arr,mid+1,ei);
		ll countMerge=merge(arr,si,mid+1,ei);

		return countMerge+countRight+countLeft;
	}
	return count;
}

void solve(){
     ll n; cin>>n;
     vi arr(n,0);
     fr(i,0,n) cin>>arr[i];

     // naive approach
     cout<<naiveSoln(arr,n)<<nL;
     ll inv=mergeSort(arr,0,n-1);
     cout<<inv<<nL;
     
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}