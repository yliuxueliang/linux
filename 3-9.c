#include"ch3.h"
int main()
{
	FILE *fp;
	int fd;
	fd = open("./test1.txt", O_RDWR);
	fp = fdopen(fd, "w+");
	fprintf(fp, "test data is %s\n", "hello world123");
	fclose(fp);
	return 0;
}
