/** 
 immortalzodd
 29.06.2024 16:45:00
 labyrinth
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

ll n,m;
vector<string> arr;
vector<vector<char>> path;
vector<vi> vis;
pii A,B;
vector<pii> disp={{1,0},{-1,0},{0,1},{0,-1}};
const string mp="DURL";

void bfs(int r,int c){
	queue<pii> qs;
	qs.push({r,c});
	vis[r][c]=1;

	while(!qs.empty()){
		auto[i,j]=qs.front();
		qs.pop();
		fr(k,0,4){
			auto[dx,dy]=disp[k];
			int p=i+dx,q=j+dy;
			if(p<0||p>=n||q<0||q>=m||vis[p][q]||arr[p][q]=='#') continue;
			vis[p][q]=1;
			qs.push({p,q});
			path[p][q]=mp[k];
		}
	}
}

void solve(){
    cin>>n>>m;
    arr.resize(n); for(string&s:arr) cin>>s;
    vis.assign(n,vi(m,0));
    path=vector<vector<char>>(n,vector<char>(m,'?'));

    fr(i,0,n){
    	fr(j,0,m){
    		if(arr[i][j]=='A'){
    			A={i,j};
    		}
    		if(arr[i][j]=='B'){
    			B={i,j};
    		}
    	}
    }

    bfs(A.first,A.second);
    if(!vis[B.first][B.second]){
    	cout<<"NO"<<nL;
    	return;
    }

    cout<<"YES"<<nL;

    string ans="";
    int r=B.first,c=B.second;
    while(r!=A.first||c!=A.second){
    	char t=path[r][c];
    	ans+=t;
    	if(t=='U') r++;
    	if(t=='R') c--;
    	if(t=='D') r--;
    	if(t=='L') c++;
    }
    reverse(all(ans));
    cout<<ans.size()<<nL;
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