#include"./ch12.h"
int main()
{
	int fd1[2],fd2[2];
	pid_t k1,k2;
	char buf[100];
	memset(buf,0,sizeof(buf));
	if((pipe(fd1))<0||(pipe(fd2))<0)
	{
		perror("pipe failed!\n");
		exit(-1);
	}
	k1=fork();
	if(k1<0)
	{
		perror("fork failed!\n");
		exit(-1);
	}
	else if(k1==0)
	{
		close(fd1[0]);
		close(fd2[1]);
		printf("inputs: \n");
		dup(fd2[1]);
		close(fd2[0]);
		
		exit(0);
		
	}
	else
	{
		
		k2=fork();
		if(k2<0)
		{
			perror("fork failed!\n");
			exit(-1);
		}
		else if(k2==0)
		{
			
			exit(0);
		}
		else
		{
			
			return 0;
		}
	}	
}
