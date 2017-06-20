


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




void *Assou(void *quantidade)

{

      int *assado= (int *) quantidade;

     

pthread_mutex_lock(&mutex_Torta);

Torta += *assado;



pthread_mutex_unlock(&mutex_Torta);

pthread_exit(NULL);

}


main( int argc, char *argv[ ], char *envp[ ] )

{

      int ct,controle,estado,Assar=4,comer=8;

      pthread_mutex_init(&mutex_Torta, NULL);

      pthread_create(&threads[0],NULL,Assou,(void *)&Assar);

      pthread_create(&threads[1],NULL,comeu,(void *)&comer);

      for(ct=0; ct<2; ct++)

      {          

        controle=pthread_join(threads[ct], (void **) &estado);

        if (controle)

        {

            perror("Erro no join");

            exit(-1);

        }

        printf("O thread %d terminou com o estado %d\n",ct,estado);

    }

printf("A quantidade de torta é =  %d\n",Torta);

      pthread_mutex_destroy(&mutex_Torta); 

      pthread_exit(NULL);

}
