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
#include<errno.h>
#include<wait.h>
#define INFILE "./in.txt"
#define OUTFILE "./out.txt"
#define MODE S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH
void err_exit(char *s)
{
	printf("Usage: %s is fliar", s);
	exit(1);
}
