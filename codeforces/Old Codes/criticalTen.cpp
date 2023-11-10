#include<iostream>
using namespace std;
int sumTen(int arr[]);
int main(){
	int t; cin>>t;
	while(t--){
		int arr[3]; cin>>arr[0]>>arr[1]>>arr[2];
		if(sumTen(arr)) cout<<"YES\n";
		else cout<<"NO\n";
	}	
}

int sumTen(int arr[]){
	for(int i=0;i<3;i++){
		for(int j=0;j<3 && j!=i;j++){
			if(arr[i]+arr[j]>=10) return 1;
		}
	}
	return 0;
}