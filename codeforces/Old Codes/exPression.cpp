#include<iostream>
using namespace std;

int op1(int a,int b,int c);
int op2(int a,int b,int c);
int op3(int a,int b,int c);
int op4(int a,int b,int c);
int op5(int a,int b,int c);
int op6(int a,int b,int c);

int main(){
		int a,b,c; cin>>a>>b>>c;
		int (*arr[6])(int,int,int)={&op1,&op2,&op3,&op4,&op5,&op6};
		int max=0;
		for(int i=0;i<6;i++){
			if(max<arr[i](a,b,c)){
				max=arr[i](a,b,c);
			}
		}
		cout<<max<<'\n';
}

int op1(int a,int b,int c){
	return a+b+c;
}

int op2(int a,int b,int c){
	return a*b*c;
}

int op3(int a,int b,int c){
	return a*(b+c);
}

int op4(int a,int b,int c){
	return (a+b)*c;
}

int op5(int a,int b,int c){
	return (a*b)+c;
}

int op6(int a,int b,int c){
	return a+(b*c);
}

