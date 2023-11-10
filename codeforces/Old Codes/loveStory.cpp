#include<iostream>
using namespace std;
int indexDiff(char s1[],char s2[],int n);
int main(){
	int t; cin>>t;
	while(t--){
		char str[11]; cin>>str;
		char str1[11]="codeforces";
		cout<<indexDiff(str1,str,0)<<endl;
	}	
}

int indexDiff(char s1[],char s2[],int n){
	if(s1[0]=='\0' && s2[0]=='\0') return n;
	else if(s1[0]!=s2[0]){
		indexDiff(s1+1,s2+1,n+1);
	}
	else{
		indexDiff(s1+1,s2+1,n);
	}
}