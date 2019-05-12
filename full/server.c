#include <stdio.h> 
#include <errno.h> 
#include <ctype.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include "fullduplex.h" 
#include <stdlib.h> 
#include<string.h> 

int main(int argc, char *argv[]) 
{ 
int rdfd, wrfd, ret_val, count, numread; 
char buf[MAX_BUF_SIZE]; 
ret_val = mkfifo(NP1, 0666); 

if ((ret_val == -1) && (errno != EEXIST))
{ 
perror("Error creating the named pipe"); 
exit (1); 
} 
ret_val = mkfifo(NP2, 0666); 

if ((ret_val == -1) && (errno != EEXIST))
{ 
perror("Error creating the named pipe"); 
exit (1); 
} 
 
rdfd = open(NP1, O_RDONLY); 
wrfd = open(NP2, O_WRONLY); 
numread = read(rdfd, buf, MAX_BUF_SIZE); 
buf[numread] = '0'; 
printf("Full Duplex Server:Read From the pipe: %s\n", buf); 
count = 0; 

while (count < numread)
{ 
buf[count] = toupper(buf[count]); 
count++; 
} 

write(wrfd, buf, strlen(buf)); 
} 
