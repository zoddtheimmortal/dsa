#include<bits/stdc++.h>
using namespace std;
struct monster{
	int hlt,idx;
};
bool cmpr(struct monster m1,struct monster m2);
int binSearch(struct monster mdx[],int si,int ei,int key);
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--){
		int n,k; cin>>n>>k;
		struct monster mdx[n];
		for(int i=0;i<n;i++){
			cin>>mdx[i].hlt;
			mdx[i].idx=i+1;
		}
		for(;;){
			sort(mdx,mdx+n,cmpr);
			if(mdx[n-1].hlt<=0) break;
			else if(mdx[n-1].hlt!=mdx[n-2].hlt){
				mdx[n-1].hlt-=k;
				cout<<"\n**************\n";
				for(int i=0;i<n;i++) cout<<mdx[i].hlt<<" ";
				cout<<endl;
				for(int i=0;i<n;i++) cout<<mdx[i].idx<<" ";
				cout<<"\n**************\n";
				if(mdx[n-1].hlt<=0){
					cout<<mdx[n-1].idx<<" ";
				}
			}
			else{
				int lb=binSearch(mdx,0,n-1,mdx[n-1].hlt);
				mdx[lb].hlt-=k;
				cout<<"\n**************\n";
				for(int i=0;i<n;i++) cout<<mdx[i].hlt<<" ";
				cout<<endl;
				for(int i=0;i<n;i++) cout<<mdx[i].idx<<" ";
				cout<<"\n**************\n";
				if(mdx[lb].hlt<=0){
					cout<<mdx[lb].idx<<" ";
				}
			}
		}
		cout<<"\n";
	}	
}

bool cmpr(struct monster m1,struct monster m2){
	return m1.hlt<m2.hlt;
}

int binSearch(struct monster mdx[],int si,int ei,int key){
	while(si<=ei){
		int m=si+(ei-si)/2;
		if(mdx[m].hlt==key) return m;
		if(mdx[m].hlt<key) si=m+1;
		else ei=m-1;
	}
}