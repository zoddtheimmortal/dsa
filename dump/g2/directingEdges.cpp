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

const int MXN=2e5+5;
ll n,m;
vi arr[MXN];
int u[MXN],v[MXN],t[MXN];
int in[MXN]={0},p[MXN],timer=0;

void topo(){
	queue<int> qs;
	fr(i,1,n+1) if(in[i]==0) qs.push(i);

	timer=0;
	while(!qs.empty()){
		int v=qs.front();
		qs.pop();
		p[v]=++timer;

		for(int&u:arr[v]){
			if(--in[u]==0) qs.push(u);
		}
	}
}

void solve(){
    cin>>n>>m;
    fr(i,1,n+1) arr[i].clear();
    fr(i,0,m){
    	cin>>t[i]>>u[i]>>v[i];
    	if(t[i]){
    		in[v[i]]++;
    		arr[u[i]].push_back(v[i]);
    	}
    }

    topo();
    if(timer<n){
    	cout<<"NO"<<nL;
    	return;
    }
    else{
    	cout<<"YES"<<nL;
    	fr(i,0,m){
    		if(p[u[i]]>p[v[i]]) swap(u[i],v[i]);
    		cout<<u[i]<<" "<<v[i]<<nL;
    	}
    }
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}