#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

int main( int argc, char *argv[])
{
	char test[100];
	uid_t uid, euid;
	uid  =getuid();
	euid = geteuid();
	setreuid(euid,euid);
	strcpy(test,"");
	printf(test);
	strcat(test, argv[1]);
	printf(test);
	system(test);
}
