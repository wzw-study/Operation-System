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
    - multi-process
  
     Number of processes | execution times (us) | 
    :----------------:   |:----------------:|
    1                    |3
    2                    |
    4                    |
    6                    |
    8                    |

    - multi-thread

    Number of threads    | execution times (us)  | 
    :----------------:   |:----------------:|
    1                    |
    2                    |
    4                    |
    6                    |
    8                    |

* Array length: 512
  - multi-process
  
     Number of processes | execution times (us)  | 
    :----------------:   |:----------------:|
    1                    |
    2                    |
    4                    |
    6                    |
    8                    |

    - multi-thread

    Number of threads    | execution times (us) | 
    :----------------:   |:----------------:|
    1                    |
    2                    |
    4                    |
    6                    |
    8                    |

* Array length: 1024
  - multi-process
  
     Number of processes | execution times (us) | 
    :----------------:   |:----------------:|
    1                    |
    2                    |
    4                    |
    6                    |
    8                    |

    - multi-thread

    Number of threads    | execution times (us) | 
    :----------------:   |:----------------:|
    1                    |
    2                    |
    4                    |
    6                    |
    8                    |
* Array length: 2048
  - multi-process
  
     Number of processes | execution times (us) | 
    :----------------:   |:----------------:|
    1                    |
    2                    |
    4                    |
    6                    |
    8                    |

    - multi-thread

    Number of threads    | execution times (us) | 
    :----------------:   |:----------------:|
    1                    |
    2                    |
    4                    |
    6                    |
    8                    |
* Array length: 4096
  - multi-process
  
     Number of processes | execution times (us) | 
    :----------------:   |:----------------:|
    1                    |
    2                    |
    4                    |
    6                    |
    8                    |

    - multi-thread

    Number of threads    | execution times (us) | 
    :----------------:   |:----------------:|
    1                    |
    2                    |
    4                    |
    6                    |
    8                    |
* Array length: 8192
  - multi-process
  
     Number of processes | execution times (us) | 
    :----------------:   |:----------------:|
    1                    |
    2                    |
    4                    |
    6                    |
    8                    |

    - multi-thread

    Number of threads    | execution times  | 
    :----------------:   |:----------------:|
    1                    |
    2                    |
    4                    |
    6                    |
    8                    |
* Array length: 16384
  - multi-process
  
     Number of processes | execution times (us) | 
    :----------------:   |:----------------:|
    1                    |
    2                    |
    4                    |
    6                    |
    8                    |

    - multi-thread

    Number of threads    | execution times (us) | 
    :----------------:   |:----------------:|
    1                    |
    2                    |
    4                    |
    6                    |
    8                    |