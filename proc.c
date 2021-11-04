#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

void printProcess(char *str);

int main(int argc, char *argv[]){
   pid_t pid;

   pid=fork();
   if(pid<0){
      /******* Fork Failed ****/
      fprintf(stderr,"Fork Error: %s\n",strerror(errno));
   }

   if(pid==0){
      /**** Child Process ****/
      printProcess("Child");
      while(1);
   }else{
      /**** Parent Process ****/
      printProcess("Parent");
      
      wait(NULL);
   }

   return 0;
}

void printProcess(char *str){
   pid_t pid, ppid, gpid;

   pid=getpid();
   ppid=getppid();
   gpid=getpgid(pid);
   printf("%s - PID[%d] Parent PID[%d] Group PID[%d]\n",str,pid,ppid,gpid);
}
