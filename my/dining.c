#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
#define N 5
#define LEFT (ph_num+4)%N
#define RIGHT (ph_num+1)%N
#define THINKING 0
#define HUNGRY 1
#define EATING 2
sem_t chopstick[5];
pthread_t philosopher[5];
int ph_num[5];
int state[5];
void test(int ph_num)
{
if(state[ph_num]==HUNGRY&&state[LEFT]!=EATING &&state[RIGHT]!=EATING)
      {
      state[ph_num]=EATING;
      sleep(2);
      printf("Philosopher %d takes fork %d and %d\n",ph_num+1,LEFT+1,ph_num+1);
      printf("Philosopher %d is Eating\n",ph_num+1);
      sem_post(&chopstick[ph_num]);
      }

}
void take_fork(int ph_num)
{
  state[ph_num]=HUNGRY;
  printf("Philosopher %d is HUNGRY\n",ph_num+1);
test(ph_num);
sem_wait(&chopstick[ph_num]);
sleep(1);

}

void put_fork(int ph_num)
{
  state[ph_num] = THINKING;
  printf("Philosopher %d putting fork %d and %d down\n",ph_num+1,LEFT+1,ph_num+1);
  printf("Philosopher %d is thinking\n",ph_num+1);
  test(LEFT);
  test(RIGHT);

}
void *philo(int num) {
  while(1)
  {
sleep(1);
take_fork(num);
put_fork(num);
}
}

void main()
{
  int i,j;
for(i=0;i<N;i++)
    {
    sem_init(&chopstick[i],0,0);
    }

  for(i=0;i<N;i++)
      {
       pthread_create(&philosopher[i],0,(void *)philo,(void *)i);
       state[i]=THINKING;
      printf("Philosopher %d is THINKING\n",i+1);
      }

 while(1);

}
