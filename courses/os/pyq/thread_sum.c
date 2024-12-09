#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

#define THREAD_CNT 1000

int sum=0;
int n;

pthread_mutex_t lock;

void* runner(void* args){
	int i=*((int*)(args));

	pthread_mutex_lock(&lock);
	sum+=((n-i)+(n-(i+1)));
	pthread_mutex_unlock(&lock);

	pthread_exit(NULL);
}

int main(void){
	scanf("%d",&n);

	sum=0;
	pthread_t tid[THREAD_CNT];
	pthread_mutex_init(&lock,NULL);

	for(int i=0;i<n;i++){
		int idx=i;
		pthread_create(&tid[i],NULL,runner,&(idx));
	}

	for(int i=0;i<n;i++){
		pthread_join(tid[i],NULL);
	}

	printf("Sum: %d\n",sum);
	return 0;
}