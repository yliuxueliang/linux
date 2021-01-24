/*兄弟进程相互通信*/
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
		sprintf(buf,"%d: %d say hello \n",getppid(),getpid());
		write(fd1[1],buf,strlen(buf));
		sleep(1);
		read(fd2[0],buf,sizeof(buf));
		printf("%d : %s\n", getppid(),buf);
		exit(0);
		
	}
	else
	{
		close(fd1[1]);
		close(fd2[0]);
		k2=fork();
		if(k2<0)
		{
			perror("fork failed!\n");
			exit(-1);
		}
		else if(k2==0)
		{
			close(fd1[1]);
			close(fd2[0]);
			read(fd1[0],buf,sizeof(buf));
			printf("%d : %s\n", getppid(),buf);
			sprintf(buf,"%d: %d say ok.\n",getppid(),getpid());
			write(fd2[1],buf,strlen(buf));
			sleep(1);
			exit(0);
		}
		else
		{
			close(fd1[1]);
			close(fd2[0]);
			close(fd1[0]);
			close(fd2[1]);		
			wait(NULL);
			wait(NULL);
			return 0;
		}
	}	
}
