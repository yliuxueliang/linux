#include"ch4.h"
int main()
{	
	int d1;
	d1 = open("./outtest.info", O_CREAT| O_TRUNC | O_WRONLY, 0644);
//	dup2(d1,1);	
	close(1);
	fcntl(d1, F_DUPFD, 1);
	printf("Redirect stdout file!\n");
	return 0;	
}
