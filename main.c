#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <string.h>
#define KEY 271829

int main(int argc, char* argv[]){
  int semdes = -2;
  if(!strcmp(argv[1], "-c") && argc > 2){
    semdes = semget(KEY, 1 , IPC_CREAT|IPC_EXCL|0644);
    if(semdes == -1)
      printf("Semaphore already exists\n");
    else
      printf("semaphore created: %d\ndefaut value set: 0\n", semdes);

    semctl(semdes, 0 , SETVAL, atoi(argv[2]));
  }
  else if(!strcmp(argv[1], "-v")){
    semdes = semget(KEY, 1 , IPC_CREAT|0644);
    printf("Semaphore value: %d\n", semctl(semdes,0,GETVAL));
  }
  else if(!strcmp(argv[1], "-r")){
    semdes = semget(KEY, 1 , IPC_CREAT|0644);
    semctl(semdes, 0 ,IPC_RMID);
    printf("Semaphore removed\n");
  }
  return 0;
}
