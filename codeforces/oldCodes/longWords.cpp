#include<iostream>
using namespace std;
int main(){
	int n; cin>>n;
	while(n--){
		char str[101]; cin>>str;
		int i=0;
		for(;str[i]!='\0';i++);
		if(i>10){
			cout<<str[0]<<i-2<<str[i-1]<<endl;
		}
		else cout<<str<<endl;

	}
}