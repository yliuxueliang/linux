#include<setjmp.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<time.h>
#include<dlfcn.h>
#include<setjmp.h>
void err_exit(char *s)
{
	printf("Usage: %s is fliar", s);
	exit(1);
}
