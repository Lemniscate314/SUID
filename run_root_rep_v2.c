#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main (int argc, char *argv[])
{
	system("./root_rep");
	printf("UID %d - EUID %d\n", getuid(), geteuid());
}
