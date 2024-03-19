#include<iostream>
using namespace std;
#define abso(a) a>0?a:-a
void mergeSort(int arr[],int si,int ei);
void merge(int arr[],int si,int mid,int ei);
int subsSum(int arr[],int n,int k);
int main(){
	int t; cin>>t;
	while(t--){
		int n,k; cin>>n>>k;
		int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
		mergeSort(arr,0,n-1);
		int ans=subsSum(arr,n,k);
		cout<<n-ans<<endl;
	}	
}

void mergeSort(int arr[],int si,int ei){
	if(si>=ei) return;
	int mid=si+((ei-si)/2);
	mergeSort(arr,si,mid);
	mergeSort(arr,mid+1,ei);
	merge(arr,si,mid,ei);
}

void merge(int arr[],int start,int mid,int end){
	int temp[end-start];
	int i=start;
	int j=mid+1;
	int k=0;
	for(;i<=mid && j<=end;){
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
	while(j<=end){
		temp[k++]=arr[j++];
	}
	k=0;
	for(int i=start;i<=end;i++){
		arr[i]=temp[k++];
	}
}

int subsSum(int arr[],int n,int k){
	int* op=new int[n];
	op[0]=1;
	for(int i=1;i<n;i++){
		op[i]=1;
		for(int j=i-1;j>=0;j--){
			int x=abso((arr[i]-arr[j]));
			if(x<=k && op[i]<=op[j]+1){
				op[i]=op[j]+1;
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(ans<op[i]) ans=op[i];
	}
	cout<<endl;
	delete[] op;
	return ans;
}