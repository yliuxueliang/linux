#include"../ch8.h"

int main()
{
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
	dlclose(fpt);
	return 0;
}
