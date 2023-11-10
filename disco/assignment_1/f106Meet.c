#include<stdio.h>
#include<stdbool.h>
#define ll long long

struct meet{
    int st,et;
};

int main(){
    int n; scanf("%d",&n);
    struct meet arr[n];
    struct meet target;

    bool ans=false;

    for(int i=0;i<n;i++){
        scanf("%d %d",&arr[i].st,&arr[i].et);
    }
    scanf("%d %d",&target.st,&target.et);

    for(int i=1;i<n;i++){
        if(arr[i-1].et<=target.st && arr[i].st>=target.et){
            ans=true;
            break;
        }
    }

    if(ans) printf("YES\n");
    else printf("NO\n");
}