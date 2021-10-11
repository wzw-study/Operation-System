
void generateData(void **array, unsigned long n, int m, int flag);
void calculate(int element, int *target, int length);
void multiProcessCalculate(int element, int target[], int length, int mutinum);
void multiThreadCalculateLock(int element, int target[], int length, int mutinum);
void multiThreadCalculateExit(int element, int target[], int length, int mutinum);
