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

bool canFinish(int n,v(vi) arr,vi indig){
	v(bool) visited(n,false);
	queue<int> qs;
	fr(i,0,n){
		if(indig[i]==0){
			qs.push(i);
			visited[i]=true;
		}
	}

	while(!qs.empty()){
		int vertex=qs.front();
		qs.pop();
		fr(i,0,n){
			if(!visited[i] && arr[vertex][i]==1){
				indig[i]-=1;
				if(indig[i]==0){
					qs.push(i);
					visited[i]=0;
				}
			}
		}
	}
	fr(i,0,n){
		if(indig[i]>0) return false;
	}
	return true;
}

void solve(){
    ll n,e; cin>>n>>e;
    v(vi) prereq(e,vi(2,0));
    v(vi) arr(n,vi(n,0));
    vi indig(n,0);
    fr(i,0,e){
    	cin>>prereq[i][0]>>prereq[i][1];
    	arr[prereq[i][1]][prereq[i][0]]=1;
    	indig[prereq[i][0]]++;
    }
    cout<<(canFinish(n,arr,indig)?"true":"false")<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}