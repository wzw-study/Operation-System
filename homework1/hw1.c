#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>


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
  struct timeval start, end;
  int count = 0;
  gettimeofday(&start, NULL);
  for (int i = 0; i < length; i++) {
    if (target[i] == element) {
      count += 1;
    }
    }
    gettimeofday(&end, NULL);
    useconds_t msec = end.tv_usec-start.tv_usec;
    time_t sec = end.tv_sec-start.tv_sec;
    printf("start: %ld.%lu\n", start.tv_sec, start.tv_usec);
    printf("end: %ld.%lu\n", end.tv_sec, end.tv_usec);
    printf("the array size is: %d\nthe elemet number is: %d\n", length, count);
    printf("single process time used:%lld.%us\n", sec, msec);
}


void mutiProcessCalculate(int element, int target[], int length, int mutinum){
  /*
  Multi-process computing
  length is the array size
  mutinum is the number of child process, restricted to multiples of 2
  */
}

void mutiThreadCalculate(int element, int target[], int length, int mutinum){
  /*
  Multi-Tread computing
  length is the array size
  mutinum is the number of child thread,restricted to multiples of 2
  */
}

int main()
{
    void *num;
    int m = 200; // the range of number
    unsigned long n = 4096; // the array number
    generateData(&num, n, m, 1);
    int *number = (int *)num;
    calculate(*(number+10), number, n);
    free(num);
    return 0;
}
