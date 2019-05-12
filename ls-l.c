#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
main(int argc,char *argv[])
{
int fd,i;
char ch[1];
if (argc<2)
{ printf("Usage: mycat filename\n");
exit(0);
}
fd=open(argv[1],O_RDONLY);
if(fd==-1)
printf("%s is not exist",argv[1]);
else
{
printf("Contents of the file %s is : \n",argv[1]);
while(read(fd,ch,1)>0)
printf("%c",ch[0]);
close(fd);
}
