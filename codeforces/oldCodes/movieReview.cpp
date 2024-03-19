#include<iostream>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int upvote=0,downvote=0;
		while(n--){
			int x; cin>>x;
			if(x==2) downvote++;
			else upvote++;
		}
		cout<<upvote<<endl;
	}	
}