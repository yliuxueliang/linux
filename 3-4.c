#include"ch3.h"
int main()
{
	FILE *fp;
	char buf[80];
	memset(buf, 0, sizeof(buf));
        if(( fp = fopen("./test1.txt","w"))==NULL)
		perror("open failed!\n");
	fgets(buf, sizeof(buf), stdin);
	printf("Content is %s\n", buf);
	fwrite(buf, 1, sizeof(buf), fp);
	fclose(fp);
	return 0;
}
