#include"./ch9.h"
int g=1;
int main()
{
	pid_t pid;
	int l=99;
	int *pt=malloc(sizeof(int));
	char *string="test string!";
	(*pt) = 9999;
	printf("----Before Fork-----");//此处加不加换行会有影响
	pid = vfork();
	if(pid<0)
	{
		fprintf(stderr,"failed to fork.Reason(%s)\n",strerror(errno));
		exit(-1);
	}
	else if(pid==0)
	{
		printf("Child : pid = %d, ppid = %d return from fork()=%d\n",getpid(), getppid(), pid);
		printf("child : init g=%d %x, l=%d %x, *pt=%d %x\n", g, &g, l, &l, *pt, pt);
		g++;
		l++;
		(*pt)++;
		printf("child : init g=%d %x, l=%d %x, *pt=%d %x\n", g, &g, l, &l, *pt, pt);
		printf("child : string = %s", string);
		exit(0);
	}
	else
	{
		sleep(2);
		printf("Parent : pid = %d, ppid = %d return from fork()=%d\n", getpid(), getppid(), pid);
		printf("parent : init g=%d %x, l=%d %x, *pt=%d %x\n", g, &g, l, &l, *pt, pt);

                g++;
                l++;
                (*pt)++;
                printf("parent : init g=%d %x, l=%d %x, *pt=%d %x\n", g, &g, l, &l, *pt, pt);
		printf("parent : string = %s",string);
		return 0;
	}
}
