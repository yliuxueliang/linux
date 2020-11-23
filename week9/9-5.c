#include"./ch9.h"
int main()
{
	pid_t i;
	i = vfork();
	if(i<0)
	{
		perror("Vfork failed!\n");
		exit(-1);
	}
	else if(i==0)
	{
		printf("child : pid=%d, ppid=%d, i=%d\n", getpid(),getppid(),i);
		return 0;
//		_exit(1);
	}
	else
	{
		wait(NULL);
		printf("parent : pid=%d, ppid=%d, i=%d\n",getpid(),getppid(),i);
//		return 0;
		_exit(0);
	}
}
