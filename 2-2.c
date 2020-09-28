#include"ch2.h"
int main()
{
	int ret;
	printf("2-2.c is running!");
	ret = write(1,"hello world!\n",13);
	sleep(100);
	exit(0);
}

