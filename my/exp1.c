#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
# define philosopher 5
sem_t chopstick[philosopher];
pthread_t ph[philosopher];
void think(int n)
{
printf("\nPhilosopher %d is thinking\n",n);
sleep(1);
}
void hungry(int n)
{
  printf("\nPhilosopher %d is hungry\n",n);
  sleep(1);
}

void eat(int n)
{
  printf("\nPhilosopher %d is eating\n",n);
  sleep(1);

}
void chop(int n,int d)
{
   if(d==1)
  printf("\nPhilosopher %d takes left chopstick\n",n);
  if(d==2)
  printf("\nPhilosopher %d takes right chopstick\n",n);
  if(d==3)
  printf("\nPhilosopher %d releases left chopstick\n",n);
  if(d==4)
  printf("\nPhilosopher %d takes right chopstick\n",n);

}
void *philo(int n)
{
while (1 ){
think(n);
hungry(n);
int left=(n-1)%philosopher;
int right=(n+1)%philosopher;
sem_wait(&chopstick[left]);
chop(n,1);
sem_wait(&chopstick[right]);
chop(n,2);
eat(n);
sem_post(&chopstick[left]);
chop(n,3);
sem_post(&chopstick[right]);
chop(n,4);
think(n);
}

}
void main()
{
int i;
for(i=0;i<philosopher;i++)
sem_init(&chopstick[i],0,1);

for(i=0;i<philosopher;i++)
pthread_create(&ph[i],0,(void *) philo,(void *)i);
while(1);
}
