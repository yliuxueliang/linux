#include "./ch10.h"
int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		printf("error!\n");
		exit(-1);
	}
	else if(pid==0)
	{
		printf("child process %d is running!\n",getpid());
		while(1);
	//	exit(0);
	}
	else
	{
		wait(NULL);
		printf("parent %d will exit!\n",getpid());
		exit(0);
	}
}
