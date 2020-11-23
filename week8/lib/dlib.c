#include"../ch8.h"
void dynamic_lib_fun_call(void)
{
	printf("Dynamic Lib Fun Called!\n");
}
void mysort_lib_call(int a[],int n)
{
	int temp,i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]<a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		printf("a[%d]:%d\n",i,a[i]);
	}
}

