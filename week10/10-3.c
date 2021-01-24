#include"./ch10.h"
int main()
{
	int r;
	printf("10-3 : pid:%d,ppid:%d\n",getpid(),getppid());
	r=execl("./test","hello","world",NULL);
	if(r==-1)
	{
		perror("execl failed!\n");
		exit(-1);
	}
	printf("after calling!\n");
	return 0;
}
