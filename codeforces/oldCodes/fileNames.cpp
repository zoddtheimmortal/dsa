#include<iostream>
using namespace std;
int removeX(char str[],int c);
int main(){
	int n; cin>>n;
	char str[n]; cin>>str;
	int x=removeX(str,0);
	cout<<x<<'\n';
	// cout<<str<<endl;	
}

int removeX(char str[],int c){
	if(str[0]=='\0') return c;
	else if(str[0]=='x' && str[1]=='x' && str[2]=='x'){
		int i=1;
		for(;str[i]!='\0';i++){
			str[i-1]=str[i];
		}
		str[i-1]='\0';
		removeX(str,c+1);
	}
	else{
		removeX(str+1,c);
	}
}