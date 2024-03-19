#include<iostream>
using namespace std;
int main(){
	int n; cin>>n;
	while(n--){
		char str[101],op[101]; cin>>str;
		int i=0;
		for(;str[i]!='\0';i++);
		if(i>10){
			int x=i-2;
			if(x>=10){
				op[0]=str[0];
				op[1]=(char)((x/10)+48);
				op[2]=(char)((x%10)+48);
				op[3]=str[i-1];
				op[4]='\0';
			}
			else{
				op[0]=str[0];
				op[1]=(char)(x+48);
				op[2]=str[i-1];
				op[3]='\0';
			}
			cout<<op<<endl;
		}
		else cout<<str<<endl;

	}
}