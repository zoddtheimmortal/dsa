/** 
 immortalzodd
 14.07.2024 19:27:57
 arrowPath
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

using pii = pair<int,int>;

ll n;
vector<string> arr(2);
vector<vi> vis;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};

void solve(){
    cin>>n;
    arr.resize(2);
    for(string&s:arr) cin>>s;

    vis.assign(2,vi(n,0));
	vis[0][0]=1;
	queue<pii> qs;
	qs.push({0,0});

	while(!qs.empty()){
		auto[r,c]=qs.front();
		qs.pop();
		if((r+c)%2==0){
			fr(i,0,4){
				int p=r+dx[i],q=c+dy[i];
				if(p<0||p>=2||q<0||q>=n||vis[p][q]) continue;
				qs.push({p,q});
				vis[p][q]=1;
			}
		}
		else{
			if(arr[r][c]=='>'){
				int p=r,q=c+1;
				if(p<0||p>=2||q<0||q>=n||vis[p][q]) continue;
				qs.push({p,q});
				vis[p][q]=1;
			}
			if(arr[r][c]=='<'){
				int p=r,q=c-1;
				if(p<0||p>=2||q<0||q>=n||vis[p][q]) continue;
				qs.push({p,q});
				vis[p][q]=1;
			}
		}
	}
	cout<<(vis[1][n-1]?"YES":"NO")<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}