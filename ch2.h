#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<errno.h>
#include<rpc/types.h>
#include<sys/utsname.h>

#define err_exit(MESSAGE) (         \
		perror(MESSAGE),    \
		exit(1)             \
	)
int gethostname (char *name, size_t size);
int sethostname (const char *name, size_t length);
int uname(struct utsname *info);
