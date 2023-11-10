#include<iostream>
using namespace std;

void revBubbleSort(int arr[],int n);
int waterCheck(int arr[],int n,int k,int x);
int main(){
	int k,n=12; cin>>k;	
	int arr[12]; 
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	revBubbleSort(arr,12);
	int x=waterCheck(arr,n,k,0);
	cout<<x<<endl;
}

void revBubbleSort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		int flag=0;
		for(int j=0;j<n-i-1;j++){
			if(arr[j]<arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0) break;
	}
}

int waterCheck(int arr[],int n,int k,int x){
	if(n==0 && k!=0) return -1;
	else if(n==0) return x;
	else if(k==0){
		return 0;
	}
	else if(arr[0]>=k){
		return x+1;
	}
	else if(arr[0]<k){
		waterCheck(arr+1,n-1,k-arr[0],x+1);
	}
}

