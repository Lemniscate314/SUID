#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>


extern char **environ;
extern int errno;

int main(int argc, char **argv) 
{
	FILE * fd;
	uid_t uid, euid;
        int isOK = 0;
	char tmpBuff [256];
	if(argc < 2) 
	{
		fprintf(stderr, "USAGE : missing parameters...\n");
                return 1;
	}
	if (!(fd=fopen("/root/.authoscripts/list", "r"))) {
		fprintf(stderr, "ERROR : Unable to open the list file on				/root/.authoscripts.\n");
		return 2;
	}
	 while (!feof(fd)) {
		 fscanf(fd, "%s", tmpBuff);
		 if (!strcmp(argv[1], tmpBuff)) {
			 isOK++;
			 break;
		 }
	 }
	 fclose (fd);
	 if (!isOK) {
		 fprintf(stderr, "ERROR : %s this file is not authorized...\n", argv[1]);
		 return 3;
	 }
	 uid=getuid();
         euid=geteuid();
         setreuid (euid, euid);
         sprintf (tmpBuff, "/root/.authoscripts/%s", argv[1]);
         execve (tmpBuff, &argv[1], environ);
         printf ("ERROR : %d - %s\n", errno, strerror(errno));
         return errno;
}
