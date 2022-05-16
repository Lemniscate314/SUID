
#include <unistd.h> 
#include <sys/types.h> 
#include <stdio.h> 
#include <stdlib.h> 


int main (int argc, char *argv[])
{
	uid_t uid, euid;
	uid = getuid();
	euid = geteuid();
	printf("UID %d - EUID %d\n", uid,euid);
	setreuid (euid,euid);
	uid = getuid();
	euid = geteuid();

        printf("UID %d - EUID %d\n", uid, euid);
	system("./root_rep");
}
