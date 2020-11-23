#include"./ch8.h"
static g=100,k;
int sum = 0;
void fun(void)
{
	int *p;
	p = (int *)malloc(sizeof(int));
	printf("p = %x, %d\n", p, sum++);
	sleep(0.01);
	fun();
}
int main()
{
	int i=0, j=0, a[10];
	static int w=100;
	int *pt=(int *)malloc(sizeof(int)*10);
	printf("address of g = %x,k = %x\n", &g, &k);
	printf("address of i = %x, j = %x,a = %x\n", &i, &j, &a);
	printf("address of w = %x\n", &w);
	printf("address of pt = %x\n", pt);
	fun();
	return 0;
}
