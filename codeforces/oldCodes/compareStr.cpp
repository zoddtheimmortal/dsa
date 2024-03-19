#include<iostream>
using namespace std;
int main(){
	char a[101],b[101];cin>>a>>b;
	int i,count=0,len=0;
	for(;a[len]!='\0';len++);
	for(i=0;a[i]!='\0';i++){
		if(a[i]!=b[i] && a[i]-32!=b[i] && b[i]-32!=a[i]){
			cout<<-1;
			break;
		}
		else count++;
	}
	if(count==len) cout<<0;
}