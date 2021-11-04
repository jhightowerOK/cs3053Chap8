#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

#define NUMBER 5


int main(int argc, char *argv[]){
   pid_t pid=0;
   int status, index;

   //** Parent Creates Children ***
   for(index=0;index<NUMBER;index++){
      if(pid==0){
         pid=fork();
      }
      if(pid<0){
         /******* Fork Failed ****/
         fprintf(stderr,"Fork Error: %s\n",strerror(errno));
      }
   }

   //** Parent Reaps Children ***
   while((pid=waitpid(-1,&status,0))>0){
      if(WIFEXITED(status)){
         printf("Child [%d] terminated with normal exit status=%d\n",pid,WEXITSTATUS(status));
      }else{
         printf("Child [%d] terminated abnormally\n",pid);
      }
   }

   return 0;
}
