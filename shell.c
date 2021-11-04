#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 500

int main(int argc, char *argv[]){
   char cmd[MAXLEN];

   while(1){
      printf("shell> ");
      fgets(cmd,MAXLEN,stdin);
      if(feof(stdin)){
         exit(0);
      }
      if(strcmp(cmd,"exit\n")==0){
         exit(0);
      }
   }

   return 0;
}
