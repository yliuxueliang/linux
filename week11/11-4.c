#include"ch11.h"
int main()
{
	pid_t pid0,pid1;
	pid0=fork();
	if(pid0<0)
	{
		perror("fork pid error!\n");
		exit(-1);	
	}
	else if(pid0==0)
	{
		printf("child1 : pid=%d,ppid=%d\n",getpid(),getppid());
		exit(0);
	}
	else
	{
		
		pid1=fork();
		if(pid1<0)
		{
			perror("fork pid error!\n");
			exit(-1);	
		}
		else if(pid1==0)
		{
			printf("child2 : pid=%d,ppid=%d\n",getpid(),getppid());
			while(1);				
			exit(0);
		}		
		
		else
		{		
			int r1,s1,r2,s2;
			r1=waitpid(pid0,&s1,0);
			r2=waitpid(pid1,&s2,WNOHANG);
			if(WIFEXITED(s1))
			{
				printf("child1 exit normal, code %d\n", WEXITSTATUS(s1));
			}
			else
			{
				
				printf("child1 exit abnormal, exit with signal %d\n", WTERMSIG(s1));
				
			}
			if(WIFEXITED(s2))
			{
				printf("child2 exit normal, code %d\n", WEXITSTATUS(s2));
			}
			else
			{
				printf("child2 exit abnormal, exit with signal %d\n", WTERMSIG(s2));
			}
			printf("parent finished!\n");
			return 0;
		}
	}
}
