#include"ch12.h"
int main()
{
	pid_t k;
	int fd[2];
	char buf[100];
	memset(buf,0,sizeof(buf));
	if(pipe(fd)<0)
	{	
		printf("pipe failed!\n");
		exit(-1);
	}
	k=fork();
	if(k<0)
	{
		perror("fork failed!\n");
		exit(-1);
	}
	else if(k==0)
	{
		close(fd[1]);
		close(0);
		dup(fd[0]);
		close(fd[0]);
		if (execl("/bin/cat","cat",NULL,NULL)==-1)	
		{
			perror("Unable to run cat");
			exit(-1);
		}				
	}
	else
	{
		close(fd[0]);
		printf("you can type a line and the line will eched:\n");
		close(1);
		dup(fd[1]);
		close(fd[1]);
		while(gets(buf) != NULL)
			puts(buf);

			
		return 0;
	}
	
}
