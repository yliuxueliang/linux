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
			r1=wait(&s1);
			r2=wait(&s2);
			if(WIFEXITED(s1))
			{
				printf("parent wait for child1 %d : exit code %d\n", r1, WEXITSTATUS(s1));
			}
			else
			{
				if(WIFSIGNALED(s1))
				{
					printf("pid %d exit with signal %d\n",r1, WEXITSTATUS(s1));
				}
			}
			if(WIFEXITED(s2))
			{
				printf("parent wait for child2 %d : exit code %d\n", r2, WEXITSTATUS(s2));
			}
			else
			{
				if(WIFSIGNALED(s2))
				{
					printf("pid %d exit with signal %d\n",r2, WEXITSTATUS(s2));
				}
			}
/*			if(r1==pid0)
			{
				printf("parent wait for child1 %d : exit code %d\n", r1, WEXITSTATUS(s1));
			}
			else
			{
				printf("parent wait for child2 %d : exit code %d\n", r1, WEXITSTATUS(s1));
			}
			if(r2==pid0)
			{
				printf("parent wait for child1 %d : exit code %d\n", r2, WEXITSTATUS(s2));
			}
			else
			{
				printf("parent wait for child2 %d : exit code %d\n", r2, WEXITSTATUS(s2));
			}*/
	//		printf("parent : exit code %d\n",WEXITSTATUS(s));
			pritnf("parent finished!\n");
			return 0;
		}
	}
}
