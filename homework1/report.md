---
title: "homework 1"
output: "homework_1"
---
# Homework 1
---
## platform

| CPU type | memory size | kernel version | machine type |
| :-----: | :----: | :----: | :----: |
| x86_64 | 12G | 4.15.0-29-generic |physical machine |

## The measurement result

I generate random arrays of integers of different lengths. The execution times of the query elements measured under single process and single thread conditions were used as a control group to measure the execution times under different process and thread conditions.


The parameters are listed in the table below.
Array type        | Integer array |
----------        | -------------
|Array length     |256, 512, 1024, 2048, 3072, 4096, 8192  |
Number of processes | 2, 4, 6, 8
Number of threads |   2, 4, 6, 8


The following list shows the execution times for different array sizes

* Array length: 256 
   Single process execution time: 0.001 (ms). the element number is: 3
    - multi-process and multi-threads execution time table list:

    Number of processes/threads | Used times (ms)<br> (process) | Used times (ms)<br> (thread with global counter) | Used times (ms)<br> (thread with pthread_exit) | 
    :---:|:---:| :---: | :---: |
    2  | 0.88 |0.571 |  6.51
    4  | 11.482 |4.09 | 6.767
    6  | 10.233 |1.452 | 16.268 
    8  | 8.455 |13.023 | 7.24

* Array length: 512
   Single process execution time: 2 (ms)
  - multi-process and multi-threads execution time table list:

    Number of processes/threads | Used times (ms)<br> (process) | Used times (ms)<br> (thread with global counter) | Used times (ms)<br> (thread with pthread_exit) | 
    :---:|:---:| :---: | :---: |
    2  |  |  | 
    4  |  |  | 
    6  |  |  |  
    8  |  |  | 


* Array length: 1024
    Single process execution time: 
  - multi-process and multi-threads execution time table list:

    Number of processes/threads | Used times (ms)<br> (process) | Used times (ms)<br> (thread with global counter) | Used times (ms)<br> (thread with pthread_exit) | 
    :---:|:---:| :---: | :---: |
    2  |  |  | 
    4  |  |  | 
    6  |  |  |  
    8  |  |  | 
* Array length: 2048
  Single process execution time: 
  - multi-process and multi-threads execution time table list:

    Number of processes/threads | Used times (ms)<br> (process) | Used times (ms)<br> (thread with global counter) | Used times (ms)<br> (thread with pthread_exit) |
    :---:|:---:| :---: | :---: |
    2  |  |  | 
    4  |  |  | 
    6  |  |  |  
    8  |  |  | 
* Array length: 3072
  Single process execution time: 
  - multi-process and multi-threads execution time table list:

    Number of processes/threads | Used times (ms)<br> (process) | Used times (ms)<br> (thread with global counter) | Used times (ms)<br> (thread with pthread_exit) | 
    :---:|:---:| :---: | :---: |
    2  |  |  | 
    4  |  |  | 
    6  |  |  |  
    8  |  |  | 
* Array length: 4096
  Single process execution time: 
  - multi-process and multi-threads execution time table list:

    Number of processes/threads | Used times (ms)<br> (process) | Used times (ms)<br> (thread with global counter) | Used times (ms)<br> (thread with pthread_exit) |
    :---:|:---:| :---: | :---: |
    2  |  |  | 
    4  |  |  | 
    6  |  |  |  
    8  |  |  | 
* Array length: 8192
  Single process execution time: 
  - multi-process and multi-threads execution time table list:

    Number of processes/threads | Used times (ms)<br> (process) | Used times (ms)<br> (thread with global counter) | Used times (ms)<br> (thread with pthread_exit) |
    :---:|:---:| :---: | :---: |
    2  |  |  | 
    4  |  |  | 
    6  |  |  |  
    8  |  |  | 