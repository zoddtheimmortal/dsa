#include<iostream>
using namespace std;
int uniqueMove(char str[],int l,int r);
int main(){
	int n; cin>>n;
	char str[n]; cin>>str;
	cout<<n+1<<endl;
}

int uniqueMove(char str[],int l,int r){
	if(str[0]=='\0') return l+r+1;
	else if(str[0]=='L') uniqueMove(str+1,l+1,r);
	else if(str[0]=='R') uniqueMove(str+1,l,r+1);

}