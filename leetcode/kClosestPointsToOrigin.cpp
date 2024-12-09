/** 
 immortalzodd
 19.06.2024 10:17:39
 kClosestPointsToOrigin
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

static int distance(vi a) { return (a[0]) * (a[0]) + (a[1]) * (a[1]); }
class Compare {
public:
    bool operator()(vi a, vi b) { return distance(a) < distance(b); }
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    int n = points.size();
    priority_queue<vi, vector<vi>, Compare> pq;
    for (int i = 0; i < k; i++)
        pq.push(points[i]);
    for (int i = k; i < n; i++) {
        cout<<distance(points[i])<<" "<<distance(pq.top());
        if (distance(points[i]) < distance(pq.top())) {
            pq.pop();
            pq.push(points[i]);
        }
    }
    vector<vi> ans;
    while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

void solve(){
    ll n,k; cin>>n>>k;
    vector<vi> arr;
    fr(i,0,n){
        int x,y; cin>>x>>y;
        arr.push_back({x,y});
    }
    vector<vi> ans=kClosest(arr,k);
    for(vi&v:ans){
        cout<<v[0]<<" "<<v[1]<<nL;
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