#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char * argv[]) {

	if (argc < 3) {
		printf("Usage ./T2.o folder_path link_name\n");
	}

	//TODO -- implement your code here;
	errno = 0;
	mkdir(argv[1], 0755);
	switch (errno) {
		case EACCES:
			printf("cannot create directory '%s': Permission denied.\n", argv[1]);
			break;
		case EEXIST:
			printf("cannot create directory '%s': File exists.\n", argv[1]);
			break;
		default:
			symlink(argv[1], argv[2]);
	}
	return 0;
}

