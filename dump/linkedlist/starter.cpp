/** 
 immortalzodd
 14.08.2024 16:47:11
 starter
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


struct Node{
    int val;
    Node* next;
    Node(){
        val=0;
        next=NULL;
    }
    Node(int x){
        val=x;
        next=NULL;
    }
};

Node* pushback(Node* tail,int val){
	Node* node=new Node(val);
	if(tail!=NULL) tail->next=node;
	return node;
}

void solve(){
    ll n; cin>>n;
    vi arr(n); for(int&x:arr) cin>>x;

    Node* head=NULL;
    Node* tail=NULL;

    for(int&x:arr){
    	tail=pushback(tail,x);
    	if(head==NULL) head=tail;
    }

    Node* curr=head;
    while(curr!=NULL){
    	cout<<curr->val<<" ";
    	curr=curr->next;
    }

    cout<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}