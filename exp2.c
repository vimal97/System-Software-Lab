#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

int buff_size=0,in=0,out=0,counter=0,temp=0,buffer[256],item;
int produced=0,consumed=0;
sem_t full;
sem_t empty; 
sem_t mutex;
void show()
{ int a;
  for(a=0;a<buff_size;++a)
   printf("\t%d",buffer[a]);
}
void *producer(int n)
{ int i,a;
  for(i=0;i<buff_size;++i)
   { sem_wait(&empty);
     sem_wait(&mutex);
     while(counter==buff_size)
        ;
     buffer[in]=counter;
     in=(in+1)%buff_size;
     counter++;
     printf("\nProducer %d",n);
     temp=counter;
     produced++;
     show();
     sleep(1);
    sem_post(&mutex);
    sem_post(&full);
   }
}
void *consumer(int b)
{ int i;
  for(i=0;i<buff_size;++i)
   {
    sem_wait(&full);
    sem_wait(&mutex);
    while(counter==0)
      ;
    item=buffer[out];
    out=(out+1)%buff_size;
    printf("\nConsumer %d",b);
        
    buffer[counter]=-1;
    counter--;
    consumed++;
    show();
    sleep(1);
    sem_post(&mutex);
    sem_post(&empty);
   }
}
int main()
{  int i,produ=1,consu=2;produced=0;
   printf("\nEnter the buffer size:");
   scanf("%d",&buff_size);
   printf("\nEnter the no of producers:");
   scanf("%d",&produ);
   printf("\nEnter the no of consumers:");
   scanf("%d",&consu);
   for(i=0;i<buff_size;++i)
      buffer[i]=-1;
   pthread_t prod,cons;
   int  exit_status;
   sem_init(&full,0,0);
   sem_init(&empty,0,buff_size); 
   sem_init(&mutex,0,1);
  for(i=0;i<produ;++i)
      pthread_create(&prod,0,(void *) producer,(void *)i);
  for(i=0;i<consu;++i)
      pthread_create(&cons,0,(void *) consumer,(void *)i);
  pthread_join(prod,&exit_status);
  
  pthread_join(cons,&exit_status);
  
 
  
  printf("\nNO 0f produced items:%d",produced);
  printf("\nNO of consumed item:%d",consumed);
  return 0;
}

