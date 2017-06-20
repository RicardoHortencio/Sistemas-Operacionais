

#include <pthread.h>

#include <stdio.h>



int Torta=10;

pthread_t threads[2]; 

pthread_mutex_t mutex_Torta;

void *comeu(void *quantidade)

{

      int *b= (int *) quantidade;


pthread_mutex_lock(&mutex_Torta);

Torta -= *b;


pthread_mutex_unlock(&mutex_Torta);

pthread_exit(NULL);

     

}



