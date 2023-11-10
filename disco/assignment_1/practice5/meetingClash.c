#include<stdio.h>

struct time{
    int x,y;
};

int main(){
    int n; scanf("%d",&n);
    struct time arr[n]; for(int i=0;i<n;i++) scanf("%d %d",&arr[i].x,&arr[i].y);
    struct time target; scanf("%d %d",&target.x,&target.y);

    if(target.y<=arr[0].x){
        printf("YES\n");
    }
    else if(target.x>=arr[n-1].y){
        printf("YES\n");
    }
    else{
        int flag=0;
        for(int i=0;i<n-1;i++){
            if(target.x>=arr[i].y && target.y<=arr[i+1].x) flag=1;
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}