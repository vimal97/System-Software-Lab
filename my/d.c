#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>
#define N 5
#define LEFT (ph_num+4)%N
#define RIGHT (ph_num+1)%N
#define THINKING 0
#define HUNGRY 1
#define EATING 2
sem_t chopstick[5];
pthread_t philosopher[5];
int state[5];
void test(int ph_num)
{
  if(state[ph_num]==HUNGRY&&state[LEFT]!=EATING&&state[RIGHT]!=EATING)
  {
    state[ph_num]=EATING;
    printf("Philosopher %d takes fork %d and %d\n",ph_num+1,LEFT+1,ph_num+1);
    printf("Philosopher %d is EATING\n",ph_num+1);
    sleep(2);
    sem_post(&chopstick[ph_num]);
  }
}
void take_fork(int ph_num)
  {
    test(ph_num);
    sem_wait(&chopstick[ph_num]);

  }
  void put_fork(int ph_num)
  {
    sem_post(&chopstick[ph_num]);
    state[ph_num]=THINKING;
    printf("Philosopher %d is THINKING\n",ph_num+1);
    test(LEFT);
    test(RIGHT);
  }
void *philo(int num)
{
while(1)
    {
      state[num]=HUNGRY;
      printf("Philosopher %d is HUNGRY\n",num+1);
      sleep(1);
      take_fork(num);
      put_fork(num);
    }
}
void main()
{int i;
for(i=0;i<N;i++)
  sem_init(&chopstick[i],0,0);

  for(i=0;i<N;i++)
      {
      state[i]=THINKING;
      pthread_create(&philosopher[i],0,(void *)philo,(void *)i);
      printf("Philosopher %d is THINKING\n",i+1);
      }
while(1);

}
