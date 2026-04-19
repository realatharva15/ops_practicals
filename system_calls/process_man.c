#include<stdio.h> //for printf 
#include<unistd.h> //for getpid()
#include<sys/types.h> //for special data types (pid_t)

int main(){
pid_t pid = getpid();
printf("The process id is: %d \n",pid);
return 0;
}
