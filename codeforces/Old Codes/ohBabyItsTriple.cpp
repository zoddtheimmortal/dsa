#include<iostream>
using namespace std;
void mergeSort(int arr[],int si,int ei);
void merge(int arr[],int si,int mid,int ei);
int tripleElement(int arr[],int n);
int main(){
	int t; cin>>t;
	while(t--){
		unsigned int n; cin>>n;
		int* arr=new int[n]; for(int i=0;i<n;i++) cin>>arr[i];
		mergeSort(arr,0,n-1);
		cout<<tripleElement(arr,n)<<endl;
	}	
}

void mergeSort(int arr[],int si,int ei){
	if(si>=ei) return;
	int mid=si+((ei-si)/2);
	mergeSort(arr,si,mid);
	mergeSort(arr,mid+1,ei);
	merge(arr,si,mid,ei);
}

void merge(int arr[],int si,int mid,int ei){
	int i=si,j=mid+1;
	int temp[ei-si];
	int k=0;
	while(i<=mid && j<=ei){
		if(arr[i]<arr[j]){
			temp[k++]=arr[i++];
		}
		else{
			temp[k++]=arr[j++];
		}
	}
	while(i<=mid){
		temp[k++]=arr[i++];
	}
	while(j<=ei){
		temp[k++]=arr[j++];
	}
	k=0;
	for(int i=si;i<=ei;i++){
		arr[i]=temp[k++];
	}
}

int tripleElement(int arr[],int n){
	if(n==0) return -1;
	else if(arr[0]==arr[1] && arr[1]==arr[2]){
		return arr[0];
	}
	else{
		tripleElement(arr+1,n-1);
	}
}