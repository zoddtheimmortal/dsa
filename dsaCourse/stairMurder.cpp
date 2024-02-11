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

ll stairN(vi arr,ll n){
    ll ans=0;
    rf(i,0,n-1){
        rf(j,0,i-1){
            if(arr[i]>arr[j]) ans+=arr[j];
        }
    }
    return ans;
}


ll merge(vi &arr,int si,int mid,int ei){
    ll ans=0;
    ll i=si,j=mid,k=0;
    vi temp(ei-si+1,0);

    while(i<mid && j<=ei){
        if(arr[i]<arr[j]){
            ans+=(ei-j+1)*(arr[i]);
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
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

ll stairE(vi &arr, ll si,ll ei){
    if(si>=ei) return 0;
    ll mid=si+(ei-si)/2;
    ll cLeft=stairE(arr,si,mid);
    ll cRight=stairE(arr,mid+1,ei);
    ll cMid=merge(arr,si,mid+1,ei);
    return cLeft+cMid+cRight;
}

void solve(){
    ll n; cin>>n;
    vi arr(n,0); fr(i,0,n) cin>>arr[i];
    cout<<"Naive "<<stairN(arr,n)<<nL;
    cout<<"Efficient "<<stairE(arr,0,n-1)<<nL;
          
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}