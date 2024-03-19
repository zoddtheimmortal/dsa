#include<iostream>
using namespace std;
int compareLetters(char str[],char x);
int main(){
	int t; cin>>t;
	while(t--){
		char str[101],x; cin>>str;
		cin>>x;
		if(compareLetters(str,x)) cout<<"YES\n";
		else cout<<"NO\n"; 
	}
}

int compareLetters(char str[],char x){
	int index=-1,flag=0,n=0;
	for(;str[n]!='\0';n++);
	for(int i=0;str[i]!='\0';i++){
		if(str[i]==x){
			index=i;
			if((index)%2==0 && (n-index+1)%2==0){
				flag=1;
				break;
			}
		}
	}
	if(flag==1) return 1;
	else return 0;
}