#include"my.h"
void prtinfo(char *s)
{
	time_t timep;
	
	FILE *fp;
	fp = fopen("log.dat","a");
	printf("%s pid:%d ppid=%d time:%s\n", s, getpid(),getppid(),ctime(&timep));
	fprintf(fp,"%s pid=%d ppid=%d exit time 2020\n", s, getpid(), getppid());
	fclose(fp);
}

