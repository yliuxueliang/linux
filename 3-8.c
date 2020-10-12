#include"ch3.h"
int main()
{
	FILE *fp;
	fp = fdopen(1,"w+");
	fprintf(fp, "test data is %s\n", "hello world\n");
	fclose(fp);
	return 0;
}
