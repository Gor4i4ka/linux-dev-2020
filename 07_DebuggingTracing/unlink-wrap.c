#define _GNU_SOURCE
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

typedef int (* unlinkat_type)(int dirfd, const char* pathname, int flags);

int unlinkat(int dirfd, const char* pathname, int flags) {
	if (strstr(pathname, "FIX"))
		return EPERM;
	unlinkat_type old_unlinkat = dlsym(RTLD_NEXT, "unlinkat");
	return old_unlinkat(dirfd, pathname, flags);
}
