#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

struct timeval start, end;

void generateData(void** array, unsigned long n, int m, int flag){
    /* generate random data
   the array size is n
   the number range size is M
   flag is the data type 1 is integers 0 strings
   */
  srand((unsigned)time(NULL));
  if (flag){
    *array = malloc(sizeof(int)*n);
    int *head = (int*) *array;
    for (int i = 0; i< n; i++){
      int num = rand() % m + 1;
      *head = num;
      head ++;
    }}else{
    *array = malloc(sizeof(char) * n);
    char* head = (char*) *array;
    for (int i = 0; i < n;i++){
      int num = rand() % 26;
      *head = (char)'A'+num;
      head++;
    }
    }
}

void calculate(int element, int* target, int length){
  /*
  Single process calculation of execution time
  */
  int count = 0;
  gettimeofday(&start, NULL);
  for (int i = 0; i < length; i++) {
    if (target[i] == element) {
      count += 1;
    }
    }
    gettimeofday(&end, NULL);
    time_t msec = end.tv_usec-start.tv_usec;
    time_t sec = end.tv_sec-start.tv_sec;
    // printf("start: %ld.%lu\n", start.tv_sec, start.tv_usec);
    // printf("end: %ld.%lu\n", end.tv_sec, end.tv_usec);
    printf("the array size is: %d\nthe elemet number is: %d\n", length, count);
    printf("single process time used:%ld.%lds\n", sec, msec);
    printf("single process time used:%ldus\n", ((end.tv_sec * 1000000 + end.tv_usec)
		  - (start.tv_sec * 1000000 + start.tv_usec)));
}


void multiProcessCalculate(int element, int target[], int length, int mutinum){
  /*
  Multi-process computing
  length is the array size
  mutinum is the number of child process, restricted to multiples of 2
  */
  int count = 0; // parent process count
  int subCount; // child process count
  int interval = length / mutinum;
  printf("child process number is %d\n", mutinum);
  gettimeofday(&start, NULL);
  for (int i = 0; i < mutinum; i++)
  {
    int pid = fork();
    if (pid <0){
      printf("fock failed\n");
      exit(-1);
    }
    if(pid == 0){
      // child process
      int subCount = 0;
      for (int j = interval * i; j < interval * (i + 1); j++){
        if (target[j] == element){
          subCount++;
        }
      }
      // printf("No. of subprocess: %d pid is: %d  sub count: %d\n",i,getpid(), subCount);
      exit(subCount);
    }
  }
      // parent process
     for (int i = 0; i < mutinum; i++){
      int endPid = wait(&subCount);
      // printf("end child pid: %d  recoive number: %d\n", endPid, subCount/256);
      count += subCount / 256;
     }
     gettimeofday(&end, NULL);
     time_t msec = end.tv_usec-start.tv_usec;
     time_t sec = end.tv_sec-start.tv_sec;
    //  printf("start: %ld.%lu\n", start.tv_sec, start.tv_usec);
    //  printf("end: %ld.%lu\n", end.tv_sec, end.tv_usec);
     printf("the array size is: %d\nthe elemet number is: %d\n", length, count);
     printf("multi-process time used:%ld.%lds\n", sec, msec);
     printf("multi-process time used:%ldus\n", ((end.tv_sec * 1000000 + end.tv_usec)
		  - (start.tv_sec * 1000000 + start.tv_usec)));
     
}

void multiThreadCalculateLock(int element, int target[], int length, int mutinum){
  /*
  Multi-Tread computing using global val
  length is the array size
  mutinum is the number of child thread,restricted to multiples of 2
  */
  static int counts = 0;
  int interval = length / mutinum;
  pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
  pthread_t Thread[mutinum];
  printf("child thread with lock number is %d\n", mutinum);
  void *calculateLock(int step)
  {
    // printf("child thread: %d\n", (int)pthread_self());
    for (int i = interval*step; i < interval*(step+1); i++){
      if (element == target[i]){
        pthread_mutex_lock(&lock);
        counts++;
        pthread_mutex_unlock(&lock);
      }
    }
    return NULL;
  }

  gettimeofday(&start, NULL);
  for (int i = 0; i < mutinum; i++){
    pthread_t thread;
    int err = pthread_create(&thread, NULL, calculateLock, i);
    if (err != 0){
      printf("can't create thread");
      exit(-1);
    }
    Thread[i] = thread;
  }
  for (int i = 0; i < mutinum; i++){
    pthread_join(Thread[i], NULL);
  }
  gettimeofday(&end, NULL);
  time_t msec = end.tv_usec-start.tv_usec;
  time_t sec = end.tv_sec-start.tv_sec;
  printf("the array size is: %d\nthe elemet number is: %d\n", length, counts);
  printf("multi-thread with lock time used:%ld.%lds\n", sec, msec);
  printf("multi-thread with lock time used:%ldus\n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
}


void multiThreadCalculateExit(int element, int target[], int length, int mutinum){
  /*
  Multi-Tread computing using pthread_exit
  length is the array size
  mutinum is the number of child thread,restricted to multiples of 2
  */
  int interval = length / mutinum;
  int count = 0;
  pthread_t Thread[mutinum];
  printf("child thread without lock number is %d\n", mutinum);
  void *calculateExit(int step)
  {
    // printf("child thread: %d\n", (int)pthread_self());
    int subCount = 0;
    for (int i = interval * step; i < interval * (step + 1); i++)
    {
      if (element == target[i]){
        subCount++;
      }
    }
    pthread_exit(subCount);
  }

  gettimeofday(&start, NULL);
  for (int i = 0; i < mutinum; i++){
    pthread_t thread;
    int err = pthread_create(&thread, NULL, calculateExit, i);
    if (err != 0){
      printf("can't create thread");
      exit(-1);
    }
    Thread[i] = thread;
  }
  for (int i = 0; i < mutinum; i++){
    int subCount;
    pthread_join(Thread[i], &subCount);
    count += subCount;
  }
  gettimeofday(&end, NULL);
  time_t msec = end.tv_usec-start.tv_usec;
  time_t sec = end.tv_sec-start.tv_sec;
  printf("the array size is: %d\nthe elemet number is: %d\n", length, count);
  printf("multi-thread with not lock time used:%ld.%lds\n", sec, msec);
  printf("multi-thread with  not lock time used:%ld us\n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));

}


int main()
{
    int m = 200; // the range of number
    unsigned long N[] = {256, 512, 1024, 2048, 4096, 8192, 16384}; // the array number
    
    for (int i = 0; i < 7; i++)
    {
      void *num;
      generateData(&num, N[i], m, 1);
      int *number = (int *)num;
      printf("One process result\n");
      printf("------------------------\n");
      calculate(*(number + 10), number, N[i]);
      printf("------------------------\n");
      printf("multi-process and multi thread result\n");
      for (int j = 2; j <= 8; j+= 2){
        printf("------------------------\n");
        multiProcessCalculate(*(number + 10), number, N[i], j);
        printf("-------------------------\n");
        multiThreadCalculateLock(*(number + 10), number, N[i], j);
        printf("-------------------------\n");
        multiThreadCalculateExit(*(number + 10), number, N[i], j);
      }

      free(num);
    }
    // void *num;
    // generateData(&num, N[6], m, 1);
    // int *number = (int *)num;
    // calculate(*(number + 10), number, [6]);
    // printf("-------------------\n");
    // multiThreadCalculateExit(*(number + 10), number, N[6], 8);
    // free(num);
    return 0;
}
