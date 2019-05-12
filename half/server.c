#include <stdio.h> 
#include <errno.h> 
#include <ctype.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include "half_duplex.h" /* For name of the named-pipe */ 
#include <stdlib.h> 

int main(int argc, char *argv[]) 
{ 
int fd, ret_val, count, numread; 
char buf[MAX_BUF_SIZE]; 
ret_val = mkfifo(HALF_DUPLEX, 0666); 

if ((ret_val == -1) && (errno != EEXIST))
{ 
perror("Error creating the named pipe\n"); 
exit (1); 
} 

fd = open(HALF_DUPLEX, O_RDONLY); 
numread = read(fd, buf, MAX_BUF_SIZE); 
buf[numread] = '0'; 
printf("Half Duplex Server: Read From the pipe : %s\n",buf); 
count = 0; 

while (count < numread)
{ 
buf[count] = toupper(buf[count]); 
count++; 
} 
printf("Half Duplex Server: Converted String : %s\n", buf); 
} 
