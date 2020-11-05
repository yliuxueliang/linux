#include"ch5.h"
int main()
{
	setvbuf(stdout, NULL,_IONBF,0);
	printf("hello world!");
	while(1);
	return 0;
}
