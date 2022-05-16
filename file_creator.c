#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>


extern char ** approxi;
extern int errno;
int main(int argc, char **argv) 
{
	FILE* fd;
	uid_t uid, euid;
	uid = getuid();
	euid = geteuid();
	printf ("UID %d - EUID %d\n", uid, euid);
	if (!(fd = fopen("/root/test","w"))) 
		printf ("Je n'ai pas pu créer le fichier /root/test avant setreuid\n");
	else 
	{
		printf ("J'ai pu créer le fichier /root/test avant setreuid\n");
                fclose(fd);
	}
	setreuid(euid, uid);
	uid = getuid();
	euid = geteuid();
	printf ("UID %d - EUID %d\n", uid, euid);



	if (!(fd = fopen("/root/test", "w")))
		printf ("Je n'ai pas pu créer le fichier /root/test après setreuid\n");
        else {
		printf ("J'ai pu créer le fichier /root/test après setreuid\n");
        fclose(fd);
	}
}
