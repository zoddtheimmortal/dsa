/** 
 immortalzodd
 06.08.2024 20:23:20
 timeMaker
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
    vi arr(4);
    fr(i,0,4) cin>>arr[i];
    sort(all(arr));

    int ans=0;
    do{
    	int hr=arr[0]*10+arr[1];
    	int min=arr[2]*10+arr[3];
    	if((hr>=0&&hr<=23)&&(min>=0&&min<=59)){
    		 ans++;
    		 cout<<hr<<" "<<min<<nL;
    	}

    }while(next_permutation(all(arr)));
    cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}