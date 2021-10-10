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
|Array length     |256, 512, 1024, 2048, 4096, 8192, 16384 |
Number of processes | 2, 4, 6, 8
Number of threads |   2, 4, 6, 8


The following list shows the execution times for different array sizes

* Array length: 256 
   Single process execution time: 1 (us)
    - multi-process and multi-threads execution time table list:

    Number of processes/threads | Used times (us)<br> (process) | Used times (us)<br> (thread with global counter) | Used times (us)<br> (thread with pthread_exit) | 
    :---:|:---:| :---: | :---: |
    2  | 825 |615  | 5322
    4  | 4813 |2909 | 6782
    6  | 4921 |6098 | 13089 
    8  | 3103 |16799 | 6530

* Array length: 512
   Single process execution time: 2 (us)
  - multi-process and multi-threads execution time table list:

    Number of processes/threads | Used times (us)<br> (process) | Used times (us)<br> (thread with global counter) | Used times (us)<br> (thread with pthread_exit) | 
    :---:|:---:| :---: | :---: |
    2  |  |  | 
    4  |  |  | 
    6  |  |  |  
    8  |  |  | 


* Array length: 1024
    Single process execution time: 
  - multi-process and multi-threads execution time table list:

    Number of processes/threads | Used times (us)<br> (process) | Used times (us)<br> (thread with global counter) | Used times (us)<br> (thread with pthread_exit) | 
    :---:|:---:| :---: | :---: |
    2  |  |  | 
    4  |  |  | 
    6  |  |  |  
    8  |  |  | 
* Array length: 2048
  Single process execution time: 
  - multi-process and multi-threads execution time table list:

    Number of processes/threads | Used times (us)<br> (process) | Used times (us)<br> (thread with global counter) | Used times (us)<br> (thread with pthread_exit) | 
    :---:|:---:| :---: | :---: |
    2  |  |  | 
    4  |  |  | 
    6  |  |  |  
    8  |  |  | 
* Array length: 4096
  Single process execution time: 
  - multi-process and multi-threads execution time table list:

    Number of processes/threads | Used times (us)<br> (process) | Used times (us)<br> (thread with global counter) | Used times (us)<br> (thread with pthread_exit) | 
    :---:|:---:| :---: | :---: |
    2  |  |  | 
    4  |  |  | 
    6  |  |  |  
    8  |  |  | 
* Array length: 8192
  Single process execution time: 
  - multi-process and multi-threads execution time table list:

    Number of processes/threads | Used times (us)<br> (process) | Used times (us)<br> (thread with global counter) | Used times (us)<br> (thread with pthread_exit) | 
    :---:|:---:| :---: | :---: |
    2  |  |  | 
    4  |  |  | 
    6  |  |  |  
    8  |  |  | 
* Array length: 16384
  Single process execution time: 
  - multi-process and multi-threads execution time table list:

    Number of processes/threads | Used times (us)<br> (process) | Used times (us)<br> (thread with global counter) | Used times (us)<br> (thread with pthread_exit) | 
    :---:|:---:| :---: | :---: |
    2  |  |  | 
    4  |  |  | 
    6  |  |  |  
    8  |  |  | 