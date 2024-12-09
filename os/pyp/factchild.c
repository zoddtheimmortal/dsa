#include<stdio.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<stdlib.h>

#define SHM_KEY 01233
#define PERMS 0644

int fact(int n){
	if(n==0||n==1) return 1;
	return n*fact(n-1);
}

int main(){
	int arr[3];
	scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);

	int fd[3][2];
	for(int i=0;i<3;i++) pipe(fd[i]);

	int* shm;
	int shmid;

	shmid=shmget(SHM_KEY,sizeof(int)*3,IPC_CREAT|PERMS);

	shm=shmat(shmid,0,0);

	pid_t child[3];

	for(int i=0;i<3;i++){
		int pid=fork();
		if(pid!=0){
			child[i]=pid;
			int p;
			close(fd[i][1]);
			read(fd[i][0],&p,sizeof(p));
			close(fd[i][0]);

			p=fact(p);
			shm[i]=p;
			exit(0);
		}
		else{
			close(fd[i][0]);
			write(fd[i][1],&arr[i],sizeof(arr[i]));
			close(fd[i][1]);
		}
		wait(NULL);
	}

	for(int i=0;i<3;i++){
		printf("Child%d: %d\n",i+1,shm[i]);
	}
}