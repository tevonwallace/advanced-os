# Advanced Operating Systems
## CPU Scheduling Algorithms

This application is used to process tasks using CPU Scheduling Algorithms. Processes can either be read from file or entered manually.


## Project Configuration
### This project was created in Xcode. 
### The C Language Dialect was set to GNU17 [-std=gnu17]
### C++ Language Dialect set to GNU++20 [-std=gnu++20]

## Executing a Single Algorithm

Clone the repository. Open in Xcode

Update the default "Scheme" and change the "Working Directory" to the location of the cloned repository.

Once the Scheme is updated. Go head and run the application.

```
|*******************************************************************************|
|          PREEMPTIVE VS NON-PREEMPTIVE PROCESS SCHEDULING ALGORITHMS           |
|*******************************************************************************|

1 -> FCFS (First Come First Serve) Scheduling
2 -> SJF (Shortest Job First) Scheduling
3 -> SRTF (Shortest Remaining Time First) Scheduling
4 -> Non-Preemptive Priority Scheduling
5 -> Preemptive Priority Scheduling
6 -> Round Robin Scheduling
7 -> Exit
```

Select the algorithm you wish to execute.


Select the algorithm you wish to execute.
```
|*******************************************************************************|
|          PREEMPTIVE VS NON-PREEMPTIVE PROCESS SCHEDULING ALGORITHMS           |
|*******************************************************************************|

1 -> FCFS (First Come First Serve) Scheduling
2 -> SJF (Shortest Job First) Scheduling
3 -> SRTF (Shortest Remaining Time First) Scheduling
4 -> Non-Preemptive Priority Scheduling
5 -> Preemptive Priority Scheduling
6 -> Round Robin Scheduling
7 -> Exit
1


How many processes would you like to enter?
[-1 = Exit, -2 = Read From File]
```

Enter the number of processes or read from a file.

```
|*******************************************************************************|
|          PREEMPTIVE VS NON-PREEMPTIVE PROCESS SCHEDULING ALGORITHMS           |
|*******************************************************************************|

1 -> FCFS (First Come First Serve) Scheduling
2 -> SJF (Shortest Job First) Scheduling
3 -> SRTF (Shortest Remaining Time First) Scheduling
4 -> Non-Preemptive Priority Scheduling
5 -> Preemptive Priority Scheduling
6 -> Round Robin Scheduling
7 -> Exit
1


How many processes would you like to enter?
[-1 = Exit, -2 = Read From File]
-2


Enter filename: 2.txt

FCFS (First Come First Serve) Scheduling
|-----------------------|
|    P1    |    0    |    4    |
|    P2    |    0    |    3    |
|    P3    |    6    |    7    |
|    P4    |    11    |    4    |
|    P5    |    12    |    2    |
|-----------------------|

|----|----|----|----|----|
| P1 | P2 | P3 | P4 | P5 |
|----|----|----|----|----|
0    4    7    14   18   20
Count: 5
Average Waiting Time: 2.8
Average Turn Around Time: 6.8
```

## Executing Multiple Algorithms
You may select multiple algorithms by using the hyphen "-" delimiter. You can also show the waiting and turn around time for each algorithm using the "-all" parameter.

```
|*******************************************************************************|
|          PREEMPTIVE VS NON-PREEMPTIVE PROCESS SCHEDULING ALGORITHMS           |
|*******************************************************************************|

1 -> FCFS (First Come First Serve) Scheduling
2 -> SJF (Shortest Job First) Scheduling
3 -> SRTF (Shortest Remaining Time First) Scheduling
4 -> Non-Preemptive Priority Scheduling
5 -> Preemptive Priority Scheduling
6 -> Round Robin Scheduling
7 -> Exit
1-3-all


How many processes would you like to enter?
[-1 = Exit, -2 = Read From File]
-2


Enter filename: 2.txt

FCFS (First Come First Serve) Scheduling
|-----------------------|
|    P1    |    0    |    4    |
|    P2    |    0    |    3    |
|    P3    |    6    |    7    |
|    P4    |    11    |    4    |
|    P5    |    12    |    2    |
|-----------------------|

|----|----|----|----|----|
| P1 | P2 | P3 | P4 | P5 |
|----|----|----|----|----|
0    4    7    14   18   20

Waiting and Turn Around Time for Individual Processes

ProcessID    Waiting Time    Turn Around Time
P1            4 - 4 = 0        4 - 0 = 4
P2            7 - 3 = 4        7 - 0 = 7
P3            8 - 7 = 1        14 - 6 = 8
P4            7 - 4 = 3        18 - 11 = 7
P5            8 - 2 = 6        20 - 12 = 8
Count: 5
Average Waiting Time: 2.8
Average Turn Around Time: 6.8


SJF (Shortest Job First) Scheduling
|-----------------------|
|    P1    |    0    |    4    |
|    P2    |    0    |    3    |
|    P3    |    6    |    7    |
|    P4    |    11    |    4    |
|    P5    |    12    |    2    |
|-----------------------|

|----|----|----|----|----|
| P2 | P1 | P3 | P5 | P4 |
|----|----|----|----|----|
0    3    7    14   16   20

Waiting and Turn Around Time for Individual Processes

ProcessID    Waiting Time    Turn Around Time
P2            3 - 3 = 0        3 - 0 = 3
P1            7 - 4 = 3        7 - 0 = 7
P3            8 - 7 = 1        14 - 6 = 8
P5            4 - 2 = 2        16 - 12 = 4
P4            9 - 4 = 5        20 - 11 = 9
Count: 5
Average Waiting Time: 2.2
Average Turn Around Time: 6.2


SRTF (Shortest Remaining Time First) Scheduling
|-----------------------|
|    P1    |    0    |    4    |
|    P2    |    0    |    3    |
|    P3    |    6    |    7    |
|    P4    |    11    |    4    |
|    P5    |    12    |    2    |
|-----------------------|

|----|----|----|----|----|
| P2 | P1 | P3 | P5 | P4 |
|----|----|----|----|----|
0    3    7    14   16   20

Waiting and Turn Around Time for Individual Processes

ProcessID    Waiting Time    Turn Around Time
P2            3 - 3 = 0        3 - 0 = 3
P1            7 - 4 = 3        7 - 0 = 7
P3            8 - 7 = 1        14 - 6 = 8
P5            4 - 2 = 2        16 - 12 = 4
P4            9 - 4 = 5        20 - 11 = 9
Average Waiting Time: 2.2
Average Turn Around Time: 6.2
```
## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.
