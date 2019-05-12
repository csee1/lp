#include<stdio.h>
#include<string.h>
#define MAX_FILE_NAME_CHARS 255
int main(int argc, char *argv[])
{
 FILE *fp;
 char file_name[MAX_FILE_NAME_CHARS], ch; 
 int i;

 if(argc<1){
    printf("Usage mycat <filename> \n");
    return 0;
 }

  for(i=1; i<=argc;i++){
    strncpy(file_name, argv[i], MAX_FILE_NAME_CHARS);

    fp=fopen(file_name, "r");
    if(fp == NULL) {
       printf("%s: No such file or directory\n", file_name);
       return 0;
    }

    while((ch=fgetc(fp)) != EOF){
         putchar(ch);
    }
    fclose(fp);
 }
 
return 0;
}
