#include<iostream>
using namespace std;

void removeX(char s[],char x){
	if(s[0]=='\0') return;
	else if(s[0]!=x) removeX(s+1,x);
	else{
		int i=1;
		for(;s[i]!='\0';i++){
			s[i-1]=s[i];
		}
		s[i-1]='\0';
		removeX(s,x);
	}

}

int main(){
	char str[100],x; cin>>str>>x;
	removeX(str,x);
	cout<<str;	
}