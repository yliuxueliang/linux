#include"./ch9.h"
static int g=0;
int main()
{
	int i;
//	g++;
//	printf("gp:%d\n",g);
//	sleep(1);
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		perror("fork child failure!\n");
		exit(-1);
	}
	else if(pid == 0)
	{
		printf("child(1) pid: %d, ppid:%d\n",getpid(),getppid());
//		g++;
//		printf("g1:%d\n",g);
//		sleep(1);
		pid_t pid1;
		pid1=fork();
		if(pid1<0)
		{
			perror("fork child failure!\n");
			exit(-1);
		}

		else if(pid1 == 0)
		{
			printf("child(1-1) pid: %d, ppid:%d\n",getpid(),getppid());
//			g++;
//			printf("g1-1:%d\n",g);
			exit(0);
		}
		else
		{
			sleep(1);
			printf("child(1-1) parent : %d\n", getpid());
		}
//		sleep(1);
		pid1=fork();
		if(pid1<0)
		{
			perror("fork child failure!\n");
			exit(-1);
		}
		else if(pid1 == 0)
		{
			printf("child(1-2) pid: %d, ppid:%d\n",getpid(),getppid());
//			g++;
//			printf("g1-2:%d\n",g);
			exit(0);
		}
		else
		{
			sleep(1);
			printf("child(1-2) parent : %d\n", getpid());
		}
		exit(0);

	}
	else
	{
		printf("child(1) parent : %d\n", getpid());
	}
//	sleep(1);
	pid=fork();
	if(pid<0)
	{
		perror("fork child failure!\n");
		exit(-1);
	}
	else if(pid == 0)
	{
		printf("child(2) pid: %d, ppid:%d\n",getpid(),getppid());
//		g++;
//		printf("g2:%d\n",g);
		exit(0);
	}
	else
	{
		sleep(1);
		printf("child(2) parent : %d\n", getpid());
	}
//	sleep(5);
//	printf("g final:%d\n",g);
	return 0;
}

