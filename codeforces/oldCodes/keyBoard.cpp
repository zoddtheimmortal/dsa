#include<iostream>
using namespace std;
void fullShift(char str[],int dir);
int main(){
	char x; cin>>x;
	char str[101]; cin>>str;
	if(x=='R'){
		fullShift(str,-1);
	}
	else if(x=='L'){
		fullShift(str,1);
	}
	cout<<str<<endl;
}

void fullShift(char str[],int dir){
	char map[31]="qwertyuiopasdfghjkl;zxcvbnm,./";
	for(int i=0;str[i]!='\0';i++){
		for(int j=0;map[j]!='\0';j++){
			if(str[i]==map[j]){
				str[i]=map[j+dir];
				break;
			}
		}
	}
	return;
}