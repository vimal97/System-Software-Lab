#include<semaphore.h>
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<math.h>
#include<stdlib.h>
#define MAXNITEMS 100000
#define MAXNTHREADS 100
int nitems;
struct
{
pthread_mutex_t mutex;
int buff[10000000];
int nput;
int nval;
int ccount;
}shared={PTHREAD_MUTEX_INITIALIZER};
void *produce(void *);
void *consume(void *);
void printbuff()
{
int i;
printf("\t");
for(i=0;i<nitems;i++)
printf("%4d",shared.buff[i]);
}
main()
{
int i,npthreads,ncthreads,*count,*c_count,temp1,temp2;
int sum=0;
pthread_t *tid_produce,*tid_consume;
nitems=20;
printf("\n\nWorking with buffer size=%d \n",nitems);
printf("\nNo. of producer threads:");
scanf("%d",&npthreads);
printf("\nNo. of consumer threads:");
scanf("%d",&ncthreads);
tid_produce=(pthread_t *)malloc(sizeof(pthread_t)*npthreads);
tid_consume=(pthread_t *)malloc(sizeof(pthread_t)*ncthreads);
count=(int *)malloc(npthreads*sizeof(int));
c_count=(int *)malloc(ncthreads*sizeof(int));
pthread_setconcurrency(npthreads+ncthreads);
for(i=0;i<nitems;i++)
shared.buff[i]=-1;
for(i=0;i<npthreads;i++)
{
count[i]=0;
pthread_create(&tid_produce[i],NULL,produce,&count[i]);
}
for(i=0;i<ncthreads;i++)
{
c_count[i]=0;
pthread_create(&tid_consume[i],NULL,consume,&c_count[i]);
}
for(i=0;i<npthreads;i++)
{
pthread_join(tid_produce[i],NULL);
}
for(i=0;i<ncthreads;i++)
{
pthread_join(tid_consume[i],NULL);
}
printf("\nProducers\n---------");
for(i=0;i<npthreads;i++)
printf("\nProducer %3d = %7d",i+1,count[i]);
printf("\n\nConsumers\n---------");
for(i=0;i<ncthreads;i++)
printf("\nConsumer %3d = %7d",i+1,c_count[i]);
printf("\n\nBuffer status\n-------------");
for(i=0;i<nitems;i++)
if(shared.buff[i]!=-1)
sum++;
printf("\n%d remaining in buffer...\n\n",sum);
exit(0);
}
void *produce(void *arg)
{
for(;;)
{
pthread_mutex_lock(&shared.mutex);
if(shared.nput>=nitems)
{
pthread_mutex_unlock(&shared.mutex);
return(NULL);
}
shared.buff[shared.nput]=shared.nval;
printf("\n%3d produced + ",shared.nput);
printbuff();
shared.nput++;
shared.nval++;
pthread_mutex_unlock(&shared.mutex);
*((int *)arg)+=1; printf("\nProducer going to sleep..."); sleep(3);
}
}
void *consume(void *arg)
{
int i;
while(1){
pthread_mutex_lock(&shared.mutex);
for(i=0;i<=shared.nput;i++){
if(shared.buff[i]!=-1)
{
printf("\n%3d consumed - ",i);
shared.buff[i]=-1; printbuff(); shared.ccount++; *((int *)arg)+=1;
printf("\nConsumer going to sleep..."); sleep(2);
break;
}
if(shared.ccount>=nitems){ pthread_mutex_unlock(&shared.mutex);
return(NULL); }
}//for
pthread_mutex_unlock(&shared.mutex);
}
}
