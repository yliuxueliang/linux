#include"./ch8.h"
static g=100,k;
int main()
{
	int i=0, j=0, a[10];
	static int w=100;
	int *pt=(int *)malloc(sizeof(int)*10);
	printf("address of g = %x,k = %x\n", &g, &k);
	printf("address of i = %x, j = %x,a = %x\n", &i, &j, &a);
	printf("address of w = %x\n", &w);
	printf("address of pt = %x\n", pt);
	return 0;
}
