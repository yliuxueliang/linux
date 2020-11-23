#include"../ch8.h"

int main()
{
	int a[10] = {1,2,3,4,9,7,8,5,6,0};
	void *fpt = dlopen("./libdlib.so", RTLD_NOW);
	if(!fpt)
	{
		printf("dlopen failed!\n");
		exit(1);
	}
	void (*fp)(void)=dlsym(fpt,"dynamic_lib_fun_call");
	if(!fp)
	{
		printf("Dlsym Failed!\n");
		exit(1);
	}
	fp();
	void (*fp_1)(int a[], int n)=dlsym(fpt,"mysort_lib_call");
	fp_1(a, 10);
	dlclose(fpt);
	return 0;
}
