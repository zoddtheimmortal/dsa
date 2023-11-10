#include<iostream>
using namespace std;
#define min(a,b) a>b?b:a
#define abs(a) (a)>0?(a):(-a)
int combinationLock(char now[],char str[],int n);
int main(){
	int n; cin>>n;
	char now[n],lock[n]; cin>>now; cin>>lock;
	int moves=combinationLock(now,lock,0);
	cout<<moves<<"\n";	
}

int combinationLock(char now[],char str[],int n){
	if(now[0]=='\0'){
		return n;
	}
	else{
		int k=abs((now[0]-str[0]));
		int m=abs((10-(k)));
		n+=min(m,k);
		combinationLock(now+1,str+1,n);
	}
}