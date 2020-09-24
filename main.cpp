#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "src/NAOValues.h"
#include "src/NAOV.cpp"
 
void *PrintHello(void *threadid){//função a ser executada quando uma thread for criada
  /*long id;
  id = (long)threadid;//conversão de void pra long
  printf("Thread %ld: Olá mundo!\n", id);*/
  pthread_exit(NULL); //finalização da thread
}

 
int main(){
    NAOV v(string("127.0.0.1"));
    //C c;    
    pthread_t t1;
    v.GoToPosture("Stand");
    long num; //identificador da thread
    num = 1; 
    int create;   
    printf("Main: criando a thread %ld\n", num);
    create = pthread_create(&t1, NULL, &NAOV::hello_helper, &v);
    v.footSteps();
    //NAOValues nao(string("127.0.0.1"));
 //criando t1 e t2 do tipo thread
     //variável que recebe o retorno da função pthread_create()
    
 //criando thread 1
    v.Rest();
    printf("Main: finalizando\n");
    return 0;
}