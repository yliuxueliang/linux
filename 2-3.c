#include"ch2.h"
int main()
{
	int ret;
	char buf[101]="0";
	//memset(buf,0,sizeof(buf));
	int fd;
	fd = open("./test.data",O_CREAT|O_TRUNC|O_RDWR,0644);
	printf("new file descript %d\n", fd);
	printf("%d 2-2.c is running!\n",getpid());
	ret = write(1,"hello world!\n",13);
	printf("ret = %d\n",ret);
	
	sleep(10);
	printf("please input data<=100\n");
	fgets(buf,100,stdin);
	ret=write(fd,buf,sizeof(buf));
	printf("ret=%d\n", ret);
	exit(0);
}

