#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source> <dest>\n", argv[0]);
        return 1;
    }
    
    int src = open(argv[1], O_RDONLY);
    int dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    char buf[BUFFER_SIZE];
    ssize_t n;
    
    while ((n = read(src, buf, BUFFER_SIZE)) > 0)
        write(dest, buf, n);
    
    close(src);
    close(dest);
    return 0;
}
