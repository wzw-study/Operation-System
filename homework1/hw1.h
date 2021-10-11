
#define TIC                                                                    \
  struct timeval start, end;                                                   \
  gettimeofday(&start, NULL);

#define TOC                                                                    \
  gettimeofday(&end, NULL);                                                    \
  double elapsedTime = (end.tv_sec - start.tv_sec) * 1000.0 +                  \
                       (end.tv_usec - start.tv_usec) / 1000.0;                 \
  printf("time used: %lf (ms)\n", elapsedTime);


void generateData(void **array, unsigned long n, int m, int flag);
void calculate(int element, int *target, int length);
void multiProcessCalculate(int element, int target[], int length, int mutinum);
void multiThreadCalculateLock(int element, int target[], int length, int mutinum);
void multiThreadCalculateExit(int element, int target[], int length, int mutinum);
