#include<stdio.h>
#include<fcntl.h> //for open() function
#include<unistd.h> //for close() function
int main(){
int fd = open("newfile.txt",O_CREAT | O_WRONLY , 0644);

if(fd==-1){     // -1 is the standard UNIX error return value
perror("open"); // perror = print error
return 1;  // file open failed (1 return ho rha)
}
printf("File opened with the kernel descriptor %d \n ", fd);
close(fd);
printf("File is closed \n");
return 0; // program is successful (0 return ho rha)
}

