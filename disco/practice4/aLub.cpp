#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int vis[N];
vector<int> g[N];
vector<int> h[N];
void printvector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int lub(vector<int> upperboundsofx, vector<int> upperboundsofy){
    int n = -1;
    for(int i=0;i<upperboundsofx.size();i++){
        for(int j=0;j<upperboundsofy.size();j++){
            if(upperboundsofx[i]==upperboundsofy[j]){
                n = upperboundsofx[i];
            }
        }
    }
    return n ;
}
void dfs1(int vertex, vector<int> &upperboundsofvertex){
    vis[vertex] = 1;
    for(int child : g[vertex]){
        if(vis[child]){
            continue;
        }
        dfs1(child,upperboundsofvertex);
    }
    upperboundsofvertex.push_back(vertex);
}
void dfs2(int vertex, vector<int> &upperboundsofvertex){
    vis[vertex] = 1;
    for(int child : h[vertex]){
        if(vis[child]){
            continue;
        }
        dfs2(child,upperboundsofvertex);
    }
    upperboundsofvertex.push_back(vertex);
}
int main(){
    int n, m , x, y;
    cin>>n>>m>>x>>y;
    vector<int> edges[n];
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        h[v2].push_back(v1);
    }
    vector<int> upperboundsofx, upperboundsofy;
    dfs1(x,upperboundsofx);
    fill(vis, vis+n, 0);
    dfs1(y,upperboundsofy);
    cout<<lub(upperboundsofx, upperboundsofy)<<endl;
    vector<int> lowerboundsofx, lowerboundsofy;
    dfs2(x,lowerboundsofx);
    fill(vis,vis+n,0);
    dfs2(y,lowerboundsofy);
    cout<<lub(lowerboundsofx,lowerboundsofy);
}