#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void maxheapify(int* arr,int n,int i){
    int left=2*i+1,right=2*i+2,x=i;
    if(left<n&&(arr[left])>(arr[x])) x=left;
    if(right<n&&(arr[right])>(arr[x])) x=right;

    if(x!=i){
        int temp=arr[i];
        arr[i]=arr[x];
        arr[x]=temp;
        maxheapify(arr,n,x);
    }
}

void minheapify(int* arr,int n,int i){
    int left=2*i+1,right=2*i+2,x=i;
    if(left<n&&(arr[left])<(arr[x])) x=left;
    if(right<n&&(arr[right])<(arr[x])) x=right;

    if(x!=i){
        int temp=arr[i];
        arr[i]=arr[x];
        arr[x]=temp;
        minheapify(arr,n,x);
    }
}

void buildHeap(int* arr,int n,int d){
    for(int i=n/2-1;i>=0;i--){
        if(d==0) maxheapify(arr,n,i);
        else minheapify(arr,n,i);
    }
}

int main(){
    freopen("median.in","r",stdin);
    freopen("median.out","w",stdout);
    int q; scanf("%d",&q);
    int* minheap=(int*) malloc(sizeof(int)*q);
    int* maxheap=(int*) malloc(sizeof(int)*q);

    int i=0,j=0;
    for(int k=0;k<q;k++){
        int y; scanf("%d",&y);
        if(y==1){
            int x; scanf("%d",&x);
            if(i<=j){
                if(j==0||x<=minheap[0]){
                    maxheap[i++]=x;
                    buildHeap(maxheap,i,0);
                }
                else{
                    int temp=minheap[0];
                    minheap[0]=x;
                    minheapify(minheap,j,0);
                    maxheap[i++]=temp;
                    buildHeap(maxheap,i,0);
                }
            }
            else{
                if(x<maxheap[0]){
                    int temp=maxheap[0];
                    maxheap[0]=x;
                    maxheapify(maxheap,i,0);
                    minheap[j++]=temp;
                    buildHeap(minheap,j,1);
                }
                else{
                    minheap[j++]=x;
                    buildHeap(minheap,j,1);
                }
            }
        }
        if(y==2){
            printf("%d\n",maxheap[0]);
        }
    }
}