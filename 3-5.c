#include"ch3.h"
int main()
{
	FILE *fp;
	char buf[80];
	memset(buf, 0, sizeof(buf));
	int ret;
        if(( fp = fopen("./test1.txt","w"))==NULL)
		perror("open failed!\n");
	ret = fgets(buf, sizeof(buf), stdin);
	printf("Content is %s\n", buf);
	fwrite(buf, 1, ret, fp);
	fclose(fp);
	return 0;
}
