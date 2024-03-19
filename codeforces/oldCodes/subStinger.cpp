#include<iostream>
using namespace std;
void removeX(char str[]);
int main(){
	int t; cin>>t;
	while(t--){
		char str[101]; cin>>str;
		// int n=0;for(;str[n]!='\0';n++);
		removeX(str);
		cout<<str<<endl;
	}	
}

void removeX(char str[]){
	if(str[2]=='\0') return;
	else if(str[0]==str[1]){
		int i=1;
		for(;str[i]!='\0';i++){
			str[i-1]=str[i];
		}
		str[i-1]='\0';
		removeX(str+1);
	}
	else{
		removeX(str+1);
	}
}