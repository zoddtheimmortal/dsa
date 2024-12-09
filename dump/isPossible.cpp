/** 
 immortalzodd
 04.08.2024 19:23:53
 isPossible
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

const int MXN=1005;
using pii = pair<int,int>;

void solve(){
    int a,b,n,m;
    cin>>a>>b>>n>>m;
    int vis[MXN][MXN]={0};

    queue<pii> qs;
    qs.push({a,b});

    while(!qs.empty()){
    	auto[r,c]=qs.front();
    	qs.pop();

    	if(r==n&&c==m){
    		cout<<"Yes"<<nL;
    		return;
    	}

    	int p=r+c,q=c;
    	if(!(p<0||p>=MXN||q<0||q>=MXN||vis[p][q])){
    		qs.push({p,q});
    		vis[p][q]=1;
    	}
    	p=c,q=r+c;
    	if(!(p<0||p>=MXN||q<0||q>=MXN||vis[p][q])){
    		qs.push({p,q});
    		vis[p][q]=1;
    	}
    }
    cout<<"No"<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}