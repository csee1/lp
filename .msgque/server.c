#include <sys/types.h> 
#include <sys/msg.h> 
#include <sys/ipc.h> 
#include <string.h> 
#include <stdio.h> 


int main (void) 
{ 

key_t ipckey; 
int mq_id; 
struct { long type; char text[100]; } mymsg; 

ipckey = ftok("/tmp/foo", 42); 
printf("My key is %d\n", ipckey); 
mq_id = msgget(ipckey, IPC_CREAT | 0666); 
printf("Message identifier is %d\n", mq_id); 
memset(mymsg.text, 0, 100); 
strcpy(mymsg.text, "Hello, world!"); 
mymsg.type = 1; 
msgsnd(mq_id, &mymsg, sizeof(mymsg), 0); 
} 
