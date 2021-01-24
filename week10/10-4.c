#include"./ch10.h"
int main()
{
//	int r;
	printf("10-4 : pid:%d,ppid:%d\n",getpid(),getppid());
	system("./test hello word 2020 11 23\n");
	printf("After calling!\n");
	return 0;
}
