#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){

printf("Note: Effective IDs will differ from Real IDs if SUID/SGID bits are set.\n");

uid_t uid = getuid();
printf("The UID of the process is : %d \n",uid);

uid_t euid = geteuid();
printf("The effective UID od the process is: %d \n",euid);

gid_t gid = getgid();
printf("The GID of the process is : %d \n", gid);

gid_t egid = getegid();
printf("The effective GID of the process is : %d \n",egid);

return 0;

}
