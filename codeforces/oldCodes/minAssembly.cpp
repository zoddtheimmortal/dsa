#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int si,int mid,int ei);
void mergeSort(int arr[],int si,int ei);

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int bsize=(n*(n-1))/2;
		int b[bsize]={0}; for(int i=0;i<bsize;i++) cin>>b[i];
		sort(b,b+bsize);
		int k=1,i=0;
		for(;i<bsize;){
			cout<<b[i]<<" ";
			i+=(n-k);
			k++;
		}
		cout<<1000000000<<endl;
	}
}

void mergeSort(int arr[],int si,int ei){
	if(si>=ei) return;
	int mid=si+(ei-si)/2;
	mergeSort(arr,si,mid);
	mergeSort(arr,mid+1,ei);
	merge(arr,si,mid,ei);
}

void merge(int arr[],int si,int mid,int ei){
	int i=si,j=mid+1,k=0;
	int temp[ei-si];
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
	k=0,i=si;
	while(i<=ei){
		arr[i++]=temp[k++];
	}
	return;
}