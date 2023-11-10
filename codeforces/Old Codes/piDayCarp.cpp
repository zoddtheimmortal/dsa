#include<iostream>
using namespace std;
int piMatches(char str[],char pi[],int k);
int main(){
	int t; cin>>t;
	char pi[32]="314159265358979323846264338327";
	while(t--){
		char str[32]; cin>>str;
		cout<<piMatches(str,pi,0)<<endl;
	}
}

int piMatches(char str[],char pi[],int k){
	if(str[0]=='\0' || str[0]!=pi[0]) return k;
	else if(str[0]==pi[0]){
		piMatches(str+1,pi+1,k+1);
	}
}