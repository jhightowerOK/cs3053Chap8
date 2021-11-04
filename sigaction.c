#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int snum);

int main(){

   struct sigaction sig;
   sig.sa_handler=handler;

   sigaction(SIGINT,&sig,NULL);
   while(1){
      printf("[%d]Program Running...\n",getpid());
      sleep(1);
   }


   return 0;
}

void handler(int snum){
   write(STDOUT_FILENO,"Signal Received\n ",17);

}
