#include"ch4.h"
char buf1[]="abcdefghij";
char buf2[]="0123456789";
int main(void)
{
	int fd;
	if((fd=open("file.hole", O_WRONLY | O_CREAT | O_APPEND), 0644))<0)
		err_exit("Creat error!");
	if(write(fd,buf1,10) != 10)
		err_exit("write error");
	if(lseek(fd, 40, SEEK_SET) == -1)
		err_exit("Lseek, error!");
	if(write(fd, buf2, 10) != 10)
		err_exit("write error!");
	return 0;
}
