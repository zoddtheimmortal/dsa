#include<iostream>
#include<string>
using namespace std;
int main(){
	int n; cin>>n;
	string p; cin>>p;
	int a,d;
	for(int i=0;i<n;i++){
		if(p[i]=='a') a++;
		else if(p[i]=='d') d++;
	}
	(a>=d)?((a==d)?(cout<<"Friendship"):(cout<<"Anton")):(cout<<"Danik");
}