#include"ch3.h"
int main(int argc, char *buf[])
{
	FILE *fp;
	int i;
	
        if(( fp = fopen("./test1.txt","w"))==NULL)
		perror("open failed!\n");
	for(i=0; i<argc; i++)
	{
		fprintf(fp,"%s", buf[i]); 
	}
	fclose(fp);
	return 0;
}
