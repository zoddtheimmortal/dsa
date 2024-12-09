/** 
 immortalzodd
 15.06.2024 09:05:36
 knightsTour
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int,int>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)


const int N=8;
ll x,y;
bool vis[N][N];
int order[N][N];
int dx[]={-1,1,2,2,-1,1,-2,-2};
int dy[]={2,2,-1,1,-2,-2,-1,1};

void solve(){
    cin>>x>>y;
    stack<pii> ss;
    ss.push({--y,--x});
    int k=1;

    while(!ss.empty()){
    	auto[r,c]=ss.top();
    	ss.pop();
    	if(r<0||r>=N||c<0||c>=N||vis[r][c]) continue;

    	order[r][c]=k++;
    	vis[r][c]=true;
    	fr(i,0,8) ss.push({r+dx[i],c+dy[i]});
    }
    fr(i,0,N){
    	fr(j,0,N) cout<<order[i][j]<<" ";
    	cout<<nL;
    }
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}