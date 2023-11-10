#include<stdio.h>

void merge(int arr[],int si,int mid,int ei){
    int i=si,j=mid+1,k=0;
    int temp[ei-si];

    while(i<=mid && j<=ei){
        if(arr[i]<arr[j]) temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
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

void mergeSort(int arr[],int si,int ei){
    if(si>=ei) return;
    int mid=si+(ei-si)/2;
    mergeSort(arr,si,mid);
    mergeSort(arr,mid+1,ei);
    merge(arr,si,mid,ei);
}

int find(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key) return 0;
    }
    return 1;
}


int main(){
    int k=0;
    int a; scanf("%d",&a);
    int arr[a]; for(int i=0;i<a;i++) scanf("%d",&arr[i]);
    int b; scanf("%d",&b);
    int brr[b]; for(int i=0;i<b;i++) scanf("%d",&brr[i]);

    int uni[a+b]; for(int i=0;i<a+b;i++) uni[i]=0;
    for(int i=0;i<a;i++) uni[i]=arr[i];

    k=a;
    for(int i=0;i<b;i++){
        if(find(arr,a,brr[i])) uni[k++]=brr[i];
    }
    printf("%d\n",k);
    mergeSort(arr,0,k-1);
    for(int i=0;i<a+b;i++){
        if(uni[i]!=0) printf("%d ",uni[i]);
    }
    printf("\n");


    mergeSort(arr,0,a-1);
    mergeSort(brr,0,b-1);
    int inr[a+b]; for(int i=0;i<a+b;i++) inr[i]=0;
    int i=0,j=0; k=0;
    while(i<a && j<b){
        if(arr[i]<brr[j]) i++;
        else if(arr[i]>brr[j]) j++;
        else{
            inr[k++]=arr[i++];
            j++;
        }
    }

    printf("%d\n",k);
    mergeSort(inr,0,a+b-1);
    for(int i=0;i<a+b;i++){
        if(inr[i]!=0) printf("%d ",inr[i]);
    }
    printf("\n");

    int diff[a]; for(int i=0;i<a;i++) diff[i]=0;
    k=0;
    for(int i=0;i<a;i++){
        if(find(brr,b,arr[i])){
            diff[k++]=arr[i];
        }
    }

    printf("%d\n",k);
    mergeSort(diff,0,a-1);
    for(int i=0;i<a;i++){
        if(diff[i]!=0) printf("%d ",diff[i]);
    }
    printf("\n");

}