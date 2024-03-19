/** 
 immortalzodd
 18.03.2024 14:53:29
 yetAnotherCoinProblem
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

vi balance({1,2,1,2,3,1,2,2,2,1,2,2,2,3});

void solve(){
    ll n; cin>>n;
    ll cost=n;
    vi arr(5,0);

    arr[0]=cost/15;
    cost%=15;
    arr[0]+=balance[cost-1];

    cost=n;
    arr[1]=cost/10;
    cost%=10;
    arr[1]+=balance[cost-1];

    cost=n;
    arr[2]=cost/6;
    cost%=6;
    arr[2]+=balance[cost-1];

    cost=n;
    arr[3]=cost/3;
    cost%=3;
    arr[3]+=balance[cost-1];

    arr[4]=n;

    ll ans=INT_MAX;
    for(int i=0;i<5;i++){
    	ans=min<ll>(ans,arr[i]);
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