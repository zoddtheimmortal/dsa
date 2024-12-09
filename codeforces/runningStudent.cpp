/** 
 immortalzodd
 01.06.2024 09:11:19
 runningStudent
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

ll n,b,s;
vi arr;
ll x,y;

double distance(ll x1,ll x2,ll y1,ll y2){
    return 1.0*(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}

void solve(){
    cin>>n>>b>>s;
    arr.resize(n,0); for(int&x:arr) cin>>x;
    cin>>x>>y;
    int ans=0; double time=0,cur_time=1e9+7;
    fr(i,1,n){
    	time=(distance(arr[i],arr[0],0,0))/b;
        time+=(distance(x,arr[i],y,0))/s;
        if(time<=cur_time){
            cur_time=time; ans=i;
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