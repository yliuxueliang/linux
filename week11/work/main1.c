#include"my.c"
int main()
{
	FILE *fp;
	fp=fopen("log.dat","w");
	fclose(fp);
	pid_t p1,p11,p2,p21;
	p1=fork();
	if(p1<0)
	{
		perror("fork pid error!\n");
		exit(-1);
	}
	else if(p1==0)
	{
		prtinfo("child1");
		p11=fork();
		if(p11<0)
		{
			perror("fork pid error!\n");
			exit(-1);
		}
		else if(p11==0)
		{
			prtinfo("child11");
			exit(0);
		}
		else
		{
			wait(NULL);
			exit(0);
		}
	}
	else
	{
		p2=fork();
		if(p2<0)
		{
			perror("fork pid error!\n");
			exit(-1);
		}
		else if(p2==0)
		{
			prtinfo("child2");
			p21=fork();
			if(p21<0)
			{
				perror("fork pid error!\n");
				exit(-1);
			}
			else if(p21==0)
			{
				prtinfo("child21");
				exit(0);
			}
			else
			{
				wait(NULL);
				exit(0);
			}

		}
		else
		{
//			int r,s;
//			r=wait(&s);
			wait(NULL);
			wait(NULL);
			prtinfo("parent");
			return 0;
		}
	}
}
