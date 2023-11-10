#include<iostream>
using namespace std;
void countRemover(char str[],char x,int k);
void strRemove(char str[],int n);
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		char str[n]; cin>>str;
		for(int i=0;str[i]!='\0';i++){
			countRemover(str+1+i,str[i],1);
		}
		cout<<str<<'\n';
	}	
}

void countRemover(char str[],char x,int k){
	if(str[0]==x){
		strRemove(str-k,k);
		return;
	}
	else{
		countRemover(str+1,x,k+1);
	}
}

void strRemove(char str[],int n){
	if(n==0) return;
	else{
		int i=1;
		for(;str[i]!='\0';i++){
			str[i-1]=str[i];
		}
		str[i-1]='\0';
		strRemove(str,n-1);
	}
}